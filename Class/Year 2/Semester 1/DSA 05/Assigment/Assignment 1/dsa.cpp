#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 100000; // Chunk size (Items per run)
const int INT_SIZE = sizeof(int);

// --- HELPER: Read Data to Verify ---
void printFileContent(const char* filename, int limit) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cout << "Could not open " << filename << " to read.\n";
        return;
    }
    
    int val;
    int count = 0;
    cout << "\n--- Preview of " << filename << " (First " << limit << " values) ---\n";
    while (inFile.read((char*)&val, INT_SIZE) && count < limit) {
        cout << val << " ";
        count++;
    }
    if (inFile.read((char*)&val, INT_SIZE)) cout << "... (more data)";
    cout << "\n-----------------------------\n";
    inFile.close();
}

// --- HELPER: Tally Verification ---
void verifyTally(const char* originalFile, const char* sortedFile) {
    ifstream in1(originalFile, ios::binary | ios::ate);
    ifstream in2(sortedFile, ios::binary | ios::ate);

    if (!in1 || !in2) {
        cout << "\n[Tally Error] Could not open files for verification.\n";
        return;
    }

    // Get file sizes in bytes
    streampos size1 = in1.tellg();
    streampos size2 = in2.tellg();

    long count1 = (long)size1 / INT_SIZE;
    long count2 = (long)size2 / INT_SIZE;

    cout << "\n--- Tally Verification ---\n";
    cout << "Original File Count: " << count1 << " integers\n";
    cout << "Sorted File Count:   " << count2 << " integers\n";

    if (count1 == count2) {
        cout << "Result: SUCCESS. The counts tally.\n";
    } else {
        cout << "Result: FAILURE. Data loss detected!\n";
    }

    in1.close();
    in2.close();
}

// --- INTERNAL SORT: Quick Sort ---

int partition(vector<int>& T, int first, int last) {
    int pivot, temp;
    int loop, cutPoint, bottom, top;
    
    pivot = T[first]; // Identify pivot (First element)
    bottom = first; 
    top = last;
    loop = 1; // always TRUE initially

    while (loop) {
        while (top > first && T[top] > pivot) { 
            top--; 
        }
        // Added boundary check (bottom < last)
        while (bottom < last && T[bottom] <= pivot) { 
            bottom++; 
        }

        if (bottom < top) {
            temp = T[bottom];
            T[bottom] = T[top];
            T[top] = temp;
        } else {
            loop = 0; // loop false
            cutPoint = top;
        }
    } 
    
    // Move pivot to correct location
    temp = T[first];
    T[first] = T[cutPoint];
    T[cutPoint] = temp;

    return cutPoint;
}

void quickSort(vector<int>& T, int first, int last) {
    int cut;
    if (first < last) {
        cut = partition(T, first, last);
        quickSort(T, first, cut - 1);
        quickSort(T, cut + 1, last);
    }
}

// --- PHASE 1: Internal Sort ---
int Phase1_CreateSortedRuns(const char* inputFile, const char* tempFile) {
    ifstream dataIn(inputFile, ios::binary);
    ofstream tempOut(tempFile, ios::binary);

    if (!dataIn.is_open() || !tempOut.is_open()) {
        cout << "Error: Failed to open files for Phase 1.\n";
        return 0;
    }

    vector<int> buffer(MAX); 
    int numSegments = 0;

    while (dataIn) {
        dataIn.read((char*)buffer.data(), MAX * INT_SIZE);
        int count = dataIn.gcount() / INT_SIZE;

        if (count == 0) break;

        // Use QuickSort instead of Insertion Sort
        quickSort(buffer, 0, count - 1);

        tempOut.write((char*)buffer.data(), count * INT_SIZE);
        numSegments++;
    }

    dataIn.close();
    tempOut.close();
    return numSegments;
}

// --- PHASE 2: External Merge Helper ---
void mergeSegments(ifstream& input, ofstream& output, long runLength) {
    int val1, val2;
    long count1 = 0, count2 = 0;

    if(!input.read((char*)&val1, INT_SIZE)) return; 
    count1 = runLength - 1;
    bool hasRun1 = true;

    if(!input.read((char*)&val2, INT_SIZE)) {
        output.write((char*)&val1, INT_SIZE);
        while(count1-- > 0 && input.read((char*)&val1, INT_SIZE)) {
             output.write((char*)&val1, INT_SIZE);
        }
        return;
    }
    count2 = runLength - 1;
    bool hasRun2 = true;

    while (hasRun1 && hasRun2) {
        if (val1 <= val2) {
            output.write((char*)&val1, INT_SIZE);
            if (count1 > 0) {
                input.read((char*)&val1, INT_SIZE);
                if (input.gcount() != INT_SIZE) hasRun1 = false;
                count1--;
            } else hasRun1 = false; 
        } else {
            output.write((char*)&val2, INT_SIZE);
            if (count2 > 0) {
                input.read((char*)&val2, INT_SIZE);
                if (input.gcount() != INT_SIZE) hasRun2 = false;
                count2--;
            } else hasRun2 = false;
        }
    }

    if (hasRun1) {
        output.write((char*)&val1, INT_SIZE);
        while (count1-- > 0 && input.read((char*)&val1, INT_SIZE)) {
            if (input.gcount() == INT_SIZE) output.write((char*)&val1, INT_SIZE);
        }
    }
    if (hasRun2) {
        output.write((char*)&val2, INT_SIZE);
        while (count2-- > 0 && input.read((char*)&val2, INT_SIZE)) {
            if (input.gcount() == INT_SIZE) output.write((char*)&val2, INT_SIZE);
        }
    }
}

// --- PHASE 2: Merge Controller ---
void Phase2_MergeRuns(const char* tempFileA, const char* tempFileB,
                      const char* outputFile, int initialNumRuns) {

    long runLength = MAX;
    int numRuns = initialNumRuns;
    bool useA = true;

    while (numRuns > 1) {
        const char* inputFile = useA ? tempFileA : tempFileB;
        const char* tempOut   = useA ? tempFileB : tempFileA;
        const char* outName   = (numRuns <= 2) ? outputFile : tempOut;

        cout << "Merging " << numRuns << " runs of size " << runLength << "..." << endl;

        ifstream input(inputFile, ios::binary);
        ofstream output(outName, ios::binary);

        int newRunCount = 0;
        int runsProcessed = 0;

        while (runsProcessed < numRuns) {
            if (runsProcessed == numRuns - 1) {
                int v;
                long limit = runLength;
                while (limit-- > 0 && input.read((char*)&v, INT_SIZE)) {
                    output.write((char*)&v, INT_SIZE);
                }
                newRunCount++;
                break;
            }

            mergeSegments(input, output, runLength);
            newRunCount++;
            runsProcessed += 2;
        }

        input.close();
        output.close();

        runLength *= 2; 
        numRuns = newRunCount;
        useA = !useA; 
    }
}

void copyFile(const char* src, const char* dst) {
    ifstream in(src, ios::binary);
    ofstream out(dst, ios::binary);
    out << in.rdbuf();
    in.close();
    out.close();
}

int main() {
    const char* original_file_name = "verybigdata.dat";
    const char* temp_file_a = "temp_segments_A.dat";
    const char* temp_file_b = "temp_segments_B.dat";
    const char* final_output_file = "sortedfile.dat";

    cout << "Starting Phase 1 (Initial Sort)..." << endl;
    int total_runs = Phase1_CreateSortedRuns(original_file_name, temp_file_a);

    if (total_runs > 0) {
        cout << "Phase 1 complete. Total runs created: " << total_runs << endl;
        
        if (total_runs > 1) {
            Phase2_MergeRuns(temp_file_a, temp_file_b, final_output_file, total_runs);
        } 
        else if (total_runs == 1) {
            cout << "Only 1 run detected. Copying directly to output." << endl;
            copyFile(temp_file_a, final_output_file);
        } 

        printFileContent(final_output_file, 100);
        verifyTally(original_file_name, final_output_file);
    } 
    else {
        cout << "Phase 1 failed (no data or file not found).\n";
        cout << "Make sure 'verybigdata.dat' exists." << endl;
    }

    cout << "\nPress Enter to exit...";
    cin.get(); 
    return 0;
}
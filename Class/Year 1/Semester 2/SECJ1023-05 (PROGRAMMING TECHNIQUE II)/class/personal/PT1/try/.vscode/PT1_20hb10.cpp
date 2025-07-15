//main function - cumpulsory
int main() {
    cin >> N; //ask the user to enter the input

    average = AVRG(10, 5, N); //call the AVRG function
    cout << average; //display teh output


    return 0;
}

//AVRG function - optional
AVRG(n1, n2, n3){
    sum = n1 + n2 + n3;
    result = sum /3;

    //Return to the calling environment
    return result;
}
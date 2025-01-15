#include <iostream>
#define n 12
using namespace std;
int main() {

    double rf[n];

    for (int i = 0; i < n ; i++){
        do{
        cout << "Enter the total rainfall for months [ ";
        cout << i <<" ] : ";
        cin >> rf[i];
        }while (rf < 0);
    }

    int sum = 0, max = -9999, low = 9999;
    for(int i = 0; i < n; i++) {
        sum += rf[i];
        
        if(rf[i] > max)
            max = rf[i];

        if(rf[i] < low)
            low = rf[i];
    }

    cout<<"The average rainfall is "<<sum/n<<endl;
	cout<<"The highest rainfall is "<<max<<endl;
	cout<<"The lowest rainfall is "<<low<<endl;

	system("pause");
	return 0;
}
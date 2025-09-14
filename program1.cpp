//program 2

#include <iostream>
using namespace std;

int main(){
    int arr[10];

    //input 10 numbers
    for(int i = 0; i < 10; i++){
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    //Bubble sort
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 - i; j++){
            if(arr[j] > arr[j + 1]){
                //swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Input numbers: 1 4 6 7 3 9 5 10 2 8 
    //Display sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}

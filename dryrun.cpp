#include <iostream>
using namespace std;

class Oddcounter {
 private :
 int numbers[10];
 int Oddcount;
 int totalsum;

public:
Oddcounter() {
Oddcount = 0;
totalsum = 0;

}

void inputNumbers(){

    cout << "Enter 10 integers: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }
}

void countoddNumbers(){
    cout << "\n Odd numbers are: ";
    for (int i = 0; i < 10; i++) {

        totalsum += numbers [i];

        if (numbers[i] % 2 != 0){
            cout << numbers[i] << " ";
            Oddcount++;
        }
}
cout << endl;
}

void displayResults() {
    cout << "Total odd Numbers: " <<Oddcount << endl;
    cout << "sum of all numbers: " << totalsum << endl;
}
};

int main() {
    Oddcounter oc;
    oc.inputNumbers();
    oc.countoddNumbers();
    oc.displayResults();

 return 0;
}
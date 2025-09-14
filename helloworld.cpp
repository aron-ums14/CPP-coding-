/*#include <iostream> 
#include <string>
 using namespace std;

 private:
 
int main() {
    std::cout << "does it work?" << std::endl;
    return 0;
}
    */

   /* #include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int size = 0;

// Add element
void insertElement(int value) {
    if (size < MAX) {
        arr[size++] = value;
        cout << "Inserted " << value << " successfully.\n";
    } else {
        cout << "Array is full.\n";
    }
}

// Delete element by value
void deleteElement(int value) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Deleted " << value << " successfully.\n";
    } else {
        cout << "Value not found.\n";
    }
}

// Display elements
void displayArray() {
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Search element using Linear Search
void searchElement(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            cout << value << " found at index " << i << ".\n";
            return;
        }
    }
    cout << value << " not found.\n";
}

// Sort using Selection Sort
void selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    cout << "Array sorted successfully.\n";
}

// Menu
void showMenu() {
    cout << "\n==== ARRAY MANAGER ====\n";
    cout << "1. Insert Element\n";
    cout << "2. Delete Element\n";
    cout << "3. Display Elements\n";
    cout << "4. Search Element\n";
    cout << "5. Sort Elements\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice, value;

    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertElement(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteElement(value);
                break;
            case 3:
                displayArray();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                searchElement(value);
                break;
            case 5:
                selectionSort();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
*/

/* #include <iostream>
#include <string>
using namespace std;

int main() {    
cout << "does it work?" << endl;

return 0;
}
*/

#include <iostream>
using namespace std;

 int main(){
     // basic display or out print
     std::cout << "Hello world" << endl;
     
     //int only is a whole number
     int num = 2;
     // double is for decimal + float is a decimal but takes two decimal
     double dec = 3.9;
     //char takes single character
     char is = 'A';
     //bool is true or false
     bool student = true;
     bool lazy = false;
     //string is the name of an object 
     string name = "Aaron";
     //output int
     cout << num << endl;
     //output double
     cout << dec << endl;
     //output char
     cout << is << endl;
     //output bool
     cout << student << endl;
     cout << lazy << endl;
     //output string
     cout << name << endl;
     return 0;
 }
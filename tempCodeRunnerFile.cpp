#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>


using namespace std;

class LoginBase {
protected:
    string username;
    string course;
    string ID;        // Example: 2025-000001
    int courseCode;   // 240 - 243
    string accountType;
    bool registered;  // flag if account is created

public:
    LoginBase() : registered(false) {}

    void generateID() {
        int randomNum = rand() % 1000000; // 0–999999
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "2025-%06d", randomNum); // 6 digits padded
        ID = buffer;
    }

    void generateCourseCode() {
        courseCode = 240 + (rand() % 4); // 240 - 243
    }

    void createAccount() {
        cout << "\n--- Create Account ---\n";
        cout << "Enter your account name: ";
        cin >> username;
        cout << "Enter your course: ";
        cin >> course;

        generateCourseCode();
        generateID();

        accountType = "Student";
        registered = true;

        cout << "\nAccount created successfully!\n";
        displayData();
    }

    bool isRegistered() {
        return registered;
    }

    bool login() {
        if (!registered) {
            cout << "No account exists. Please create an account first.\n";
            return false;
        }

        string inputID;
        int attempts = 0;
        while (attempts < 3) {
            cout << "\n--- Login ---\n";
            cout << "Enter your ID: ";
            cin >> inputID;

            if (inputID == ID) {
                cout << "Login successful! Welcome, " << username << "!\n";
                return true;
            } else {
                cout << "Incorrect ID. Try again.\n";
                attempts++;
            }
        }
        cout << "Too many failed attempts. Exiting program.\n";
        return false;
    }

    void displayData() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Name : " << username << endl;
        cout << "Course       : " << course << endl;
        cout << "Course Code  : " << courseCode << endl;
        cout << "ID           : " << ID << endl;
        cout << "Account Type : " << accountType << endl;
    }
};

struct Subject {
    string name;
    string type; // Major or Minor
    double grade;
};

// Array-based table display
void displayStudentRecordArray() {
    Subject subjects[5] = {
        {"Programming 1", "Major", 89.5},
        {"Data Structures", "Major", 91.0},
        {"Database Systems", "Major", 88.0},
        {"Web Development", "Minor", 85.5},
        {"Discrete Math", "Minor", 87.0}
    };
    int n = 5;

    cout << "\n--- IT Course Grading System (Array) ---\n";
    cout << left << setw(20) << "Subject"
         << setw(10) << "Type"
         << setw(10) << "Grade" << endl;
    cout << "------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << left << setw(20) << subjects[i].name
             << setw(10) << subjects[i].type
             << setw(10) << subjects[i].grade << endl;
    }
    cout << "------------------------------------------\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    LoginBase student;
    int choice;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Login (Locked until account created)\n";
        cout << "2. Student Record (Locked until login)\n";
        cout << "3. Account\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (student.isRegistered()) {
                    if (student.login()) {
                        int subChoice;
                        do {
                            cout << "\n--- Student Record System Menu ---\n";
                            cout << "1. Student Record (Array)\n";
                            cout << "2. Account\n";
                            cout << "3. Logout\n";
                            cout << "Enter your choice: ";
                            cin >> subChoice;

                            switch (subChoice) {
                                case 1:
                                    displayStudentRecordArray();
                                    break;
                                case 2:
                                    student.displayData();
                                    break;
                                case 3:
                                    cout << "Logging out...\n";
                                    break;
                                default:
                                    cout << "Invalid choice.\n";
                            }
                        } while (subChoice != 3);
                    }
                } else {
                    cout << "You must create an account first!\n";
                }
                break;

            case 2:
                cout << "Locked! Please login first.\n";
                break;

            case 3:
                student.createAccount();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

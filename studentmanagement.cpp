// Student Management System

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

// Trim helper 
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

// Safe integer input
int readInt(const string &prompt, int lo = INT_MIN, int hi = INT_MAX) {
    string line;
    int val;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) continue;
        line = trim(line);
        if (line.empty()) {
            cout << "Input cannot be empty.\n";
            continue;
        }
        try {
            val = stoi(line);
        } catch (...) {
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        if (val < lo || val > hi) {
            cout << "Enter a value between " << lo << " and " << hi << ".\n";
            continue;
        }
        return val;
    }
}

// ======================= ADMIN ACCOUNT =======================
class Admin {
private:
    string username;
    string password;
    string ID;
    bool registered;

public:
    Admin() : registered(false) {}

    void generateID() {
        // Generate a random number between 0 and 99,999
        int randomNum = rand() % 100000;
        // Create a string stream to build the ID string
        ostringstream oss;
        // Format the ID as "ADM-" followed by a 5-digit number with leading zeros
        oss << "ADM-" << setw(5) << setfill('0') << randomNum;
        // Assign the formatted string to the ID variable
        ID = oss.str();
    }

    void signUp() {
        cout << "\n--- Admin Sign Up ---\n";
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);

        generateID();
        registered = true;

        cout << "\nAdmin account created successfully!\n";
        cout << "Your Admin ID: " << ID << "\n";
    }

    bool login() {
        if (!registered) {
            cout << "No admin account exists. Please sign up first.\n";
            return false;
        }

        string inputUser, inputPass;
        cout << "\n--- Admin Login ---\n";
        cout << "Enter username: ";
        getline(cin, inputUser);
        cout << "Enter password: ";
        getline(cin, inputPass);

        if (inputUser == username && inputPass == password) {
            cout << "\nLogin successful! Welcome, " << username << ".\n";
            return true;
        } else {
            cout << "Invalid credentials.\n";
            return false;
        }
    }

    bool isRegistered() const { return registered; }
};

// ======================= STUDENT RECORD =======================
struct Student {
    string fullName;
    string program; // BSIT or BSCS
    string yearSection;
    string status;  // Enrolled or Not
    string studentID;
};

// ======================= STUDENT MANAGEMENT =======================
class StudentManagement {
private:
    vector<Student> students;

    string generateStudentID() {
        int randomNum = rand() % 1000000;
        ostringstream oss;
        oss << "STU-" << setw(6) << setfill('0') << randomNum;
        return oss.str();
    }

public:
    void addStudent() {
        Student s;
        cout << "\n--- Add Student ---\n";
        cout << "Enter Full Name: ";
        getline(cin, s.fullName);

        cout << "Enter Program (BSIT/BSCS): ";
        getline(cin, s.program);

        cout << "Enter Year & Section (e.g., 2A, 3B): ";
        getline(cin, s.yearSection);

        cout << "Enrolled? (Yes/No): ";
        getline(cin, s.status);

        s.studentID = generateStudentID();
        students.push_back(s);

        cout << "Student added successfully! ID: " << s.studentID << "\n";
    }

    void viewStudents() {
        if (students.empty()) {
            cout << "\nNo students found.\n";
            return;
        }

        cout << "\n--- Student List ---\n";
        cout << left << setw(15) << "Student ID"
             << setw(25) << "Full Name"
             << setw(10) << "Program"
             << setw(12) << "Year/Section"
             << setw(10) << "Status" << "\n";
        cout << "-------------------------------------------------------------------\n";

        for (const auto &s : students) {
            cout << left << setw(15) << s.studentID
                 << setw(25) << s.fullName
                 << setw(10) << s.program
                 << setw(12) << s.yearSection
                 << setw(10) << s.status << "\n";
        }
    }

    void deleteStudent() {
        if (students.empty()) {
            cout << "\nNo students to delete.\n";
            return;
        }

        string id;
        cout << "Enter Student ID to delete: ";
        getline(cin, id);

        auto it = remove_if(students.begin(), students.end(),
                            [&](const Student &s) { return s.studentID == id; });

        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student with ID " << id << " deleted successfully.\n";
        } else {
            cout << "No student found with ID: " << id << "\n";
        }
    }
};

// ======================= MAIN SYSTEM =======================
int main() {
    srand(time(nullptr));
    Admin admin;
    StudentManagement sm;

    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Sign Up (Admin)\n";
        cout << "2. Login (Admin)\n";
        cout << "3. Exit\n";
        int choice = readInt("Enter choice: ", 1, 3);

        if (choice == 1) {
            admin.signUp();
        } else if (choice == 2) {
            if (admin.login()) {
                // Dashboard
                while (true) {
                    cout << "\n--- Admin Dashboard ---\n";
                    cout << "1. Add Student\n";
                    cout << "2. View Students\n";
                    cout << "3. Delete Student\n";
                    cout << "4. Logout\n";
                    int opt = readInt("Enter choice: ", 1, 4);

                    if (opt == 1) sm.addStudent();
                    else if (opt == 2) sm.viewStudents();
                    else if (opt == 3) sm.deleteStudent();
                    else if (opt == 4) {
                        cout << "Logging out...\n";
                        break;
                    }
                }
            }
        } else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }
    }

    return 0;
}

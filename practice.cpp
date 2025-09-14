// coding practice #1
#include <iostream>
#include <string> // Needed for string
using namespace std;

void function() {
    cout << "This is inside the function!" << endl;
}

int main() {
    int age = 26;
    float weight = 75.90;
    bool stud = true;
    
    cout << "How old are you? " << age << endl;
    cout << "What is your weight? " << weight << endl;
    cout << "Are you a student: " << (stud ? "yes" : "no") << endl;
    
    int section;
    cout << "What section are you? ";
    cin >> section; // Read integer
    cin.ignore(); // Clear newline from buffer
    
    cout << "Oh you are " << section << " same section" << endl;
    
    string name;
    cout << "What is your name btw? ";
    getline(cin, name); // Read full name
    
    cout << "Oh hello " << name << " nice to meet you" << endl;
    
    function();
    return 0;
}



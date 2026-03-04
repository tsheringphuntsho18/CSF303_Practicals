// Personal Introduction Output
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Write C++ code here
    string name;
    int std_number;
    string course;

    cout << "Enter Your Name: ";
    getline(cin, name);

    cout << "Enter Your Student Number: ";
    cin >> std_number;

    cout << "Enter Your Course: ";
    cin.ignore();  // Clear the newline character from the input buffer
    getline(cin, course);
    cout << endl;

    cout << "==============================" << endl;
    cout << endl;
    cout << "Student Profile" << endl;
    cout << endl;
    cout << "==============================" << endl;
    cout << endl;
    cout << "Name: " << name << endl;
    cout << endl;
    cout << "Student Number: " << std_number << endl;
    cout << endl;
    cout << "Course: " << course << endl;
    cout << endl;
    cout << "==============================" << endl;
    return 0;
}
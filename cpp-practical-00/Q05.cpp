// Conditional Grade Classification
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "Tshering Phuntsho";
    string std_num = "02230310";
    int marks;
    string grade;
    string result;

    cout << "Enter your marks (0-100): ";
    cin >> marks;

    // Input validation
    if (marks < 0 || marks > 100) {
        cout << "Error: Marks must be between 0 and 100." << endl;
        return 0;
    }

    // Extract first name
    string firstName;
    size_t pos = name.find(' ');
    
    if (pos != string::npos) {
        firstName = name.substr(0, pos);
    } else {
        firstName = name; 
    }

    // Classify grade
    if (marks >= 75) {
        grade = "Distinction";
    } else if (marks >= 60) {
        grade = "Merit";
    } else if (marks >= 40) {
        grade = "Pass";
    } else {
        grade = "Fail";
    }

    // Personalized result message
    result = "Dear " + firstName +
             ", you scored " + to_string(marks) +
             " marks and achieved a " + grade + " classification.";

    // Output
    cout << "\n------------------------------" << endl;
    cout << "Student  : " << name << " (" << std_num << ")" << endl;
    cout << "Mark     : " << marks << endl;
    cout << "Grade    : " << grade << endl;
    cout << "Result   : " << result << endl;
    cout << "------------------------------" << endl;

    return 0;
}
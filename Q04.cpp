// User Input & Type Conversion
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int std_num;
    int age;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your student number: ";
    cin >> std_num;

    cout << "Enter your age: ";
    cin >> age;

    // Year they were born
    int year_of_birth = 2026 - age;

    // Year when they are 100 years old
    int year_at_age_100 = year_of_birth + 100;

    // Output the result
    cout << "------------------------------------" << endl;
    cout << " " << endl;
    cout << "Summary" << endl;
    cout << " " << endl;
    cout << "------------------------------------" << endl;
    cout << " " << endl;
    cout << "Name             : " << name << endl;
    cout << " " << endl;
    cout << "Student No       : " << std_num << endl;
    cout << " " << endl;
    cout << "Year of Birth    : " << year_of_birth << endl;
    cout << " " << endl;
    cout << "Year at Age 100  : " << year_at_age_100 << endl;

    return 0;
}

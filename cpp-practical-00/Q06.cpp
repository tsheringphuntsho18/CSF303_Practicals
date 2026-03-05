// Loop-Based Pattern Generation
#include <iostream>
#include <string>
using namespace std;

int main() {

    string first_name = "Tshering";
    string full_name = "Tshering Phuntsho";
    int std_num = 2230310;

    // print first name
    int first_nameLength = first_name.length();
    cout << "Name repeated (" << first_nameLength << " times):" << endl;
    for (int i = 0; i < first_nameLength; i++) {
        cout << first_name << endl;
    }
    cout << " " << endl;

    // print a right-angled triangle of asterisks
    cout << "Triangle (height = " << full_name.length() << "):" << endl;
    for (int i = 1; i <= full_name.length(); i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << " " << endl;

    // Print the multiplication table (1 to 10) for the last digit of your student number.
    int last_digit = std_num % 10;
    cout << "Times Table for " << last_digit << " (last digit of " << std_num << "):" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << last_digit << " x " << i << " = " << last_digit * i << endl;
    }
    return 0;
}
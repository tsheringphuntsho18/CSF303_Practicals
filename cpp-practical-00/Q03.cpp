// String Manipulation & Analysis
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // Length of the name
    int length;
    length = name.length();

    // Convert to uppercase
    string upper_name = name;
    for (char & c : upper_name) {
        c = toupper(c);
    }

    // Convert to lowercase
    string lower_name = name;
    for (char & c : lower_name) {
        c = tolower(c);
    }

    // Get the initials
    string initials;
    for (int i = 0; i < name.length(); i++) {
        if (i == 0 || name[i - 1] == ' ') {
            if (!initials.empty()) {
                initials += '.';
            }
            initials += name[i];
        }
    }

    // length of first name
    size_t first_space_pos = name.find(" ");

    if (first_space_pos != string::npos) {
        first_space_pos = first_space_pos;
    } else {
        first_space_pos = name.length();
    }

    // Output
    cout << "==================================" << endl;
    cout << "Full Name      : " << name << endl;
    cout << "Total Length   : " << length << endl;
    cout << "Uppercase      : " << upper_name << endl;
    cout << "Lowercase      : " << lower_name << endl;
    cout << "Initials       : " << initials << endl;
    cout << "First Name Len : " << first_space_pos << endl;

    return 0;
}
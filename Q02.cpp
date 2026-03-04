// Arithmetic with Student Number
#include <iostream>
#include <string>

using namespace std;

int main() {
    int std_number;
    cout << "Enter Your Student Number: ";
    cin >> std_number;

    // Sum of individual digits
    int sum = 0;
    int temp_std_number = std_number;
    while (temp_std_number > 0) {
        sum += temp_std_number % 10;
        temp_std_number /= 10;
    }
    
    // Even or Odd
    string evenodd;
    if (std_number % 2 == 0) {
        evenodd = "Even";
    } else {
        evenodd = "Odd";
    }

    // Remainder
    int remainder;
    remainder = std_number % 7;

    // Multiplication
    int multiplication;
    multiplication = std_number * 3;

    // Output
    cout << "Student Number  : " << std_number << endl;
    cout << "Digit Sum       : " << sum << endl;
    cout << "Odd / Even      : " << evenodd << endl;
    cout << "Remainder (% 7) : " << remainder << endl;
    cout << "Multiplied by 3 : " << multiplication << endl;

    return 0;
}
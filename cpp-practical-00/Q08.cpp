// Function Design & Modular Programming
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countVowels(string s) {
    int count = 0;
    for (char c : s) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {

    int studentNumber = 2230310;
    string fullName = "Tshering Phuntsho";

    // Output
    cout << "\n=========================================" << endl;
    cout << "\nFunction Results for " << fullName << endl;
    cout << "\nStudent No: " << studentNumber << endl;
    cout << "\n=========================================" << endl;
    cout << "\ndigitSum(" << studentNumber << ")     : " << digitSum(studentNumber) << endl;
    cout << "\nisPrime(" << studentNumber << ")      : " << (isPrime(studentNumber) ? "Yes" : "No") << endl;
    cout << "\ncountVowels(" << fullName << ")       : " << countVowels(fullName) << endl;
    cout << "\nreversedString(" << fullName << ")    : " << reverseString(fullName) << endl;
    cout << "\n=========================================" << endl;

    return 0;
}
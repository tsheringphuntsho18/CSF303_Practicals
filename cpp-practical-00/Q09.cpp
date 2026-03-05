// Vector & Dynamic Collections
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {

    vector<int> v2230310;
    int input;

    cout << "Enter 6 values: ";
    // Enter 6 values: 45 12 87 34 65 22
    for (int i = 0; i < 6; i++) {
        cin >> input;
        v2230310.push_back(input);
    }

    cout << "\nOriginal    : ";
    for (int n : v2230310) {
        cout << n << " ";
    }
    cout << endl;
    // Original: 45 12 87 34 65 22

    sort(v2230310.begin(), v2230310.end());
    cout << "\nSorted    : ";
    for (int n : v2230310) {
        cout << n << " ";
    }
    cout << endl;
    // Sorted: 12 22 34 45 65 87

    int minVal = *min_element(v2230310.begin(), v2230310.end());
    int maxVal = *max_element(v2230310.begin(), v2230310.end());
    int sum = accumulate(v2230310.begin(), v2230310.end(), 0);
    double average = static_cast<double>(sum) / v2230310.size();

    cout << "\nMin: " << minVal << endl;
    cout << "\nMax: " << maxVal << endl;
    cout << "\nSum: " << sum << endl;
    cout << "\nAverage: " << fixed << setprecision(2) << average << endl;

    v2230310.erase(remove_if(v2230310.begin(), v2230310.end(),
        [average](int n) { return n < average; }), v2230310.end());

    cout << "\nAfter removing below average: ";
    for (int n : v2230310) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
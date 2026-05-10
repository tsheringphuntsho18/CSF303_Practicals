// Manachar's Algorithm
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> manacher(const string& s) {
    string T = "^#";
    for (char c : s) {
        T += c;
        T += '#';
    }
    T += '$';

    int n = T.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; i++) {
        if (i < R) {
            P[i] = min(R - i, P[2 * C - i]);
        }
        while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    return P;
}

int main() {
    string s = "racecar";
    vector<int> p = manacher(s);
    for (int i = 1; i < p.size() - 1; i++) {
        cout << p[i] << " ";
    }
    return 0;
}

// Classes & Object-Oriented Design
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    int studentNumber;
    vector<float> marks;

public:
    Student(const string& name_, int studentNumber_) : name(name_), studentNumber(studentNumber_) {}

    void addMark(float m) {
        marks.push_back(m);
    }

    float getAverage() const {
        if (marks.empty()) return 0.0f;
        float sum = accumulate(marks.begin(), marks.end(), 0.0f);
        return sum / marks.size();
    }

    float getHighest() const {
        if (marks.empty()) return 0.0f;
        return *max_element(marks.begin(), marks.end());
    }

    float getLowest() const {
        if (marks.empty()) return 0.0f;
        return *min_element(marks.begin(), marks.end());
    }

    string getClassification() const {
        float avg = getAverage();
        if (avg >= 75.0f) return "Distinction";
        if (avg >= 60.0f) return "Merit";
        if (avg >= 50.0f) return "Pass";
        return "Fail";
    }

    void printReport() const {
        cout << "================================================\n\n";
        cout << "ACADEMIC REPORT\n\n";
        cout << "================================================\n\n";

        cout << left << setw(16) << "Student Name" << " : " << name << "\n\n";
        cout << left << setw(16) << "Student No" << " : " << studentNumber << "\n\n";

        cout << left << setw(16) << "Marks Entered" << " : " << marks.size() << "\n\n";

        cout << left << setw(16) << "Marks" << " : ";
        for (size_t i = 0; i < marks.size(); ++i) {
            cout << (int)marks[i];
            if (i + 1 < marks.size()) cout << " ";
        }
        cout << "\n\n";

        cout << left << setw(16) << "Average" << " : " << fixed << setprecision(2) << getAverage() << "\n\n";
        cout << left << setw(16) << "Highest" << " : " << (int)getHighest() << "\n\n";
        cout << left << setw(16) << "Lowest" << " : " << (int)getLowest() << "\n\n";
        cout << left << setw(16) << "Classification" << " : " << getClassification() << "\n\n";

        cout << "================================================\n";
    }
};

int main() {
    Student s("Tshering Phuntsho", 2230310);

    // Add at least 5 marks
    s.addMark(78.5f);
    s.addMark(92.0f);
    s.addMark(88.0f);
    s.addMark(54.25f);
    s.addMark(66.75f);
    s.addMark(66.75f);
    s.addMark(54.25f);
    s.addMark(88.0f);

    s.printReport();

    return 0;
}
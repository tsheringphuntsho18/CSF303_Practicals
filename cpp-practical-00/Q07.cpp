// Array Operations & Statistics
#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string name = "Tshering Phuntsho";
    string std_num = "02230310";
    int tshering_marks[5] = {85, 72, 90, 65, 78};

    // Compute highest mark
    int highest = tshering_marks[0];
    for (int i = 1; i < 5; i++) {
        if (tshering_marks[i] > highest) {
            highest = tshering_marks[i];
        }
    }

    // Compute lowest mark
    int lowest = tshering_marks[0];
    for (int i = 1; i < 5; i++) {
        if (tshering_marks[i] < lowest) {
            lowest = tshering_marks[i];
        }
    }

    // Compute average mark
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += tshering_marks[i];
    }
    double average = sum / 5.0;

    // Count marks above average
    int count_above_average = 0;
    for (int i = 0; i < 5; i++) {
        if (tshering_marks[i] >= average) {
            count_above_average++;
        }
    }    

    // Output
    cout << " "  << endl;
    cout << "Student: " << name << " | No: " << std_num << endl;
    cout << " "  << endl;
    cout << "-----------------------------------------" << endl;
    cout << " "  << endl;
    cout << "Index\tMark\tBar" << endl;
    // Display bar chart
    for (int i = 0; i < 5; i++) {
        cout << "\n[" << i << "]\t" << tshering_marks[i] << "\t";
        for (int j = 0; j < tshering_marks[i] / 10; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << " "  << endl;
    cout << "-----------------------------------------" << endl;
    cout << " "  << endl;
    cout << "Highest : " << highest << endl;
    cout << " "  << endl;
    cout << "Lowest : " << lowest << endl;
    cout << " "  << endl;
    cout << "Average : " << average << endl;
    cout << " "  << endl;
    cout << "Above average: " << count_above_average << " mark(s)" << endl;

    return 0;
} 
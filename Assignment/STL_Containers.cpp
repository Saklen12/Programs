#include <iostream>
#include <map>
#include <vector>
#include <numeric>  // For accumulate
#include <algorithm> // For max_element
#include <string>

using namespace std;

int main() {
    map<string, vector<int>> studentRecords;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records with Averages\n";
        cout << "3. Display Topper\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            vector<int> marks(3);
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter marks in 3 subjects:\n";
            for (int i = 0; i < 3; ++i) {
                cout << "Subject " << (i+1) << ": ";
                cin >> marks[i];
            }
            studentRecords[name] = marks;
        }
        else if (choice == 2) {
            cout << "\nStudent Records:\n";
            for (const auto& [name, marks] : studentRecords) {
                int total = accumulate(marks.begin(), marks.end(), 0);
                float average = total / 3.0;
                cout << "Student: " << name << ", Marks: ";
                for (int mark : marks) {
                    cout << mark << " ";
                }
                cout << ", Average: " << average << endl;
            }
        }
        else if (choice == 3) {
            if (studentRecords.empty()) {
                cout << "No records found.\n";
                continue;
            }

            string topper;
            float maxAverage = 0;

            for (const auto& [name, marks] : studentRecords) {
                float avg = accumulate(marks.begin(), marks.end(), 0) / 3.0;
                if (avg > maxAverage) {
                    maxAverage = avg;
                    topper = name;
                }
            }

            cout << "\nTopper: " << topper << " with average " << maxAverage << endl;
        }
        else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

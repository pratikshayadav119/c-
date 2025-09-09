// gpa calculator
#include <iostream>
#include <iomanip>

using namespace std;

// Class Definition
class GPACalculator {
    private:
        int numSubjects;
        float totalWeightedMarks;
        float totalCredits;
        float gpa;

    public:
        // Constructor
        GPACalculator() {
            numSubjects = 0;
            totalWeightedMarks = 0.0;
            totalCredits = 0.0;
            gpa = 0.0;
        }

        // Input marks and credits
        void inputMarksAndCredits() {
            cout << "Enter number of subjects: ";
            cin >> numSubjects;

            for (int i = 1; i <= numSubjects; i++) {
                float marks, credits;
                cout << "Enter marks for subject " << i << " (out of 100): ";
                cin >> marks;

                cout << "Enter credits for subject " << i << ": ";
                cin >> credits;

                totalWeightedMarks += marks * credits;
                totalCredits += credits;
            }
        }

        // Calculate GPA
        void calculateGPA() {
            float averageMarks = totalWeightedMarks / totalCredits;
            gpa = (averageMarks / 100) * 4;  // Assuming GPA scale out of 4
        }

        // Display GPA with 2 decimal places
        void displayGPA() {
            cout << fixed << setprecision(2);
            cout << "Your GPA is: " << gpa << endl;
        }
};

// Main Function
int main() {
    GPACalculator student;

    student.inputMarksAndCredits();
    student.calculateGPA();
    student.displayGPA();

    return 0;
}


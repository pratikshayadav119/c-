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

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Class Definition
class GPACalculator {
    private:
        int numSubjects;
        float totalWeightedGradePoints;
        float totalCredits;
        float gpa;

        // Helper function to calculate grade point from marks
        float getGradePoint(float marks) {
            if (marks >= 90) return 4.0;
            else if (marks >= 80) return 3.5;
            else if (marks >= 70) return 3.0;
            else if (marks >= 60) return 2.5;
            else if (marks >= 50) return 2.0;
            else return 0.0;  // Fail
        }

    public:
        // Constructor
        GPACalculator() {
            numSubjects = 0;
            totalWeightedGradePoints = 0.0;
            totalCredits = 0.0;
            gpa = 0.0;
        }

        // Input subject details
        void inputSubjects() {
            cout << "Enter number of subjects: ";
            cin >> numSubjects;
            cin.ignore();  // Clear input buffer

            cout << fixed << setprecision(2);

            for (int i = 1; i <= numSubjects; i++) {
                string subjectName;
                float marks, credits;

                cout << "\nSubject " << i << ":" << endl;
                cout << "Enter subject name: ";
                getline(cin, subjectName);

                cout << "Enter marks (out of 100): ";
                cin >> marks;

                cout << "Enter credits: ";
                cin >> credits;
                cin.ignore();  // Clear input buffer

                float gradePoint = getGradePoint(marks);

                cout << "Subject: " << subjectName << ", Grade Point: " << gradePoint << endl;

                totalWeightedGradePoints += gradePoint * credits;
                totalCredits += credits;
            }
        }

        // Calculate GPA
        void calculateGPA() {
            gpa = totalWeightedGradePoints / totalCredits;
        }

        // Display GPA
        void displayGPA() {
            cout << "\nOverall GPA: " << gpa << endl;
        }
};

// Main Function
int main() {
    GPACalculator student;

    student.inputSubjects();
    student.calculateGPA();
    student.displayGPA();

    return 0;
}


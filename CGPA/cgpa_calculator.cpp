#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct grade {
    int credits;
    char grades;
};

int main() {
    double totalCredits = 0;
    double cal = 0;
    int number;
    double gpa;

    cout << "Enter the number of courses taken: ";
    cin >> number;
    vector<grade> cgpa(number);
    
    if (number > 0) { // Changed to only check if number > 0
        for (int i = 0; i < number; i++) {
            cout << "Enter the credit attained for course " << i + 1 << ": ";
            while (!(cin >> cgpa[i].credits) || cgpa[i].credits <= 0) {
                cout << "Enter a valid credit (positive integer): ";
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }
            cout << "Enter the grade for course " << i + 1 << " (A, B, C, D, E, F): ";
            cin >> cgpa[i].grades;
            cout << "\n"; // Ensured line break

            totalCredits += cgpa[i].credits;
        }
    } else {
        cout << "\n";
        cout << "Enter a valid input \n" << "CGPA cannot be calculated";
    }
    
    for (const auto& course : cgpa) {
            switch (course.grades) {
                case 'A':
                    cal += 5 * course.credits;
                    break;
                case 'B':
                    cal += 4 * course.credits;
                    break;
                case 'C':
                    cal += 3 * course.credits;
                    break;
                case 'D':
                    cal += 2 * course.credits;
                    break;
                case 'E':
                    cal += 1 * course.credits;
                    break;
                case 'F':
                    cal += 0 * course.credits;
                    break;
                default:
                    cout << "Invalid grade entered. Exiting.\n";
                    return 1; // Exit the program due to invalid grade
            }

    }
    
    gpa = cal / totalCredits;
    cout << gpa;

    


}

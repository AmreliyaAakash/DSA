#include <iostream>
#include <string>
using namespace std;

int main() {
    int score;

    cout << "Enter your score: ";
    cin >> score;

    string grade = 
    (score >= 90) ? "A" :
    (score >= 80) ? "B" :
    (score >= 70) ? "C" :
     (score >= 60) ? "D" : "F";

    cout << "Your grade is " << grade << ". ";

    switch (grade[0]) {
        case 'A':
            cout << "Excellent work! ";
            break;
        case 'B':
            cout << "Well done! ";
            break;
        case 'C':
            cout << "Good job! ";
            break;
        case 'D':
            cout << "You passed, but you could do better. ";
            break;
        case 'F':
            cout << "Sorry, you failed. ";
            break;
        default:
            cout << "Invalid grade. ";
    }

   
    if (grade == "A" || grade == "B" || grade == "C" || grade == "D") {
        cout << "Congratulations! You are eligible for the next level." << endl;
    } else {
        cout << "Please try again next time." << endl;
    }

    return 0;
}
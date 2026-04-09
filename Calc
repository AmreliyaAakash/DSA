#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divi(int a, int b) {
    return a / b;
}

int mod(int a, int b) {
    return a % b;
}

int main() {
    int a, b, choice;
    char ch;

    do {
        cout << "\n===== CALCULATOR =====\n";
        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n";
        cout << "Enter choice: ";
        cin >> choice;

        cout << "Enter two numbers: ";
        cin >> a >> b;

        switch(choice) {
            case 1:
                cout << "Result = " << add(a, b);
                break;

            case 2:
                cout << "Result = " << sub(a, b);
                break;

            case 3:
                cout << "Result = " << mul(a, b);
                break;

            case 4:
                if (b != 0)
                    cout << "Result = " << divi(a, b);
                else
                    cout << "Cannot divide by zero";
                break;

            case 5:
                cout << "Result = " << mod(a, b);
                break;

            default:
                cout << "Invalid choice!";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
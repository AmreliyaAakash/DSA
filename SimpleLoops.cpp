#include <iostream>
using namespace std;

int main() {
    cout << "Q.1 Alphabet Skipper\n";
    for (char ch = 'a'; ch <= 'z'; ch += 4) {
        cout << ch << " ";
    }
    cout << "\n\n";

    cout << "Q.2 Digit Counter\n";
    int num1, count = 0;
    cout << "Enter a number: ";
    cin >> num1;
    
    int temp1 = abs(num1); 
    if (temp1 == 0) count = 1;
    while (temp1 > 0) {
        count++;
        temp1 /= 10;
    }
    cout << "Total number of digits: " << count << "\n\n";

    
    cout << "Q.3 Digit Addition\n";
    int num2;
    cout << "Enter a number: ";
    cin >> num2;
    
    int temp2 = abs(num2);
    int lastDigit = temp2 % 10;
    while (temp2 >= 10) {
        temp2 /= 10;
    }
    int firstDigit = temp2;
    
    cout << "Sum of first and last digit: " << firstDigit + lastDigit << "\n";

    return 0;
}

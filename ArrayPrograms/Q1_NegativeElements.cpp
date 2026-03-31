#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the array's size: ";
    cin >> size;

    // Assuming a max size of 100 for simplicity
    int a[100]; 
    
    cout << "\nEnter array's elements:\n";
    for(int i = 0; i < size; i++) {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }

    cout << "\nNegative elements from an Array: ";
    bool first = true;
    for(int i = 0; i < size; i++) {
        if(a[i] < 0) {
            if(!first) {
                cout << ", ";
            }
            cout << a[i];
            first = false;
        }
    }
    cout << "\n";

    return 0;
}

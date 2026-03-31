#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the array's row & column size: ";
    cin >> size;

    int a[100][100];
    cout << "Enter array's elements:\n";
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }

    cout << "\nThe transpose matrix of an array:\n";
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            // Note: Outputting a[j][i] transposes the matrix on the fly
            cout << a[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

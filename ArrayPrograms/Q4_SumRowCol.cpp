#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the array's row size: ";
    cin >> rows;
    cout << "Enter the array's column size:\n";
    cin >> cols;

    int a[100][100];
    
    cout << "\nEnter array's elements:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }

    int rowNum;
    cout << "\nEnter row number: ";
    cin >> rowNum;

    cout << "Elements of row " << rowNum << ": ";
    int rowSum = 0;
    for(int j = 0; j < cols; j++) {
        cout << a[rowNum][j];
        if(j < cols - 1) {
            cout << ", ";
        }
        rowSum += a[rowNum][j];
    }
    cout << "\nThe sum of a row " << rowNum << ": " << rowSum << "\n";

    int colNum;
    cout << "\nEnter column number: ";
    cin >> colNum;

    cout << "Elements of column " << colNum << ": ";
    int colSum = 0;
    for(int i = 0; i < rows; i++) {
        cout << a[i][colNum];
        if(i < rows - 1) {
            cout << ", ";
        }
        colSum += a[i][colNum];
    }
    cout << "\nThe sum of column " << colNum << ": " << colSum << "\n";

    return 0;
}

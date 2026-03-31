#include <iostream>

using namespace std;

int main() {
    // Q.1 Right half triangle pattern
    cout << "Q.1 Right half triangle pattern\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = 41; j <= 40 + i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Q.2 Floyd's triangle pattern
    cout << "Q.2 Floyd's triangle pattern\n";
    int num = 11;
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= i; j++) {
            cout << num++ << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Q.3 Left half triangle pattern
    cout << "Q.3 Left half triangle pattern\n";
    for(int i = 5; i >= 1; i--) {
        for(int k = 1; k < i; k++) {
            cout << "  ";
        }
        for(int j = i; j <= 5; j++) {
            cout << j;
        }
        cout << "\n";
    }
    cout << "\n";

    // Q.4 Inverted Left half triangle pattern
    cout << "Q.4 Inverted Left half triangle pattern\n";
    for(int i = 5; i >= 1; i--) {
        for(int k = 0; k < 5 - i; k++) {
            cout << "  "; 
        }
        for(int j = 1; j <= i; j++) {
            if (j % 2 == 1) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }
    cout << "\n";

    // Q.5 Full Pyramid pattern
    cout << "Q.5 Full Pyramid pattern\n";
    for(int i = 5; i >= 1; i--) {
        for(int k = 1; k < i; k++) {
            cout << " ";
        }
        for(int j = i; j <= 5; j++) {
            cout << j;
        }
        for(int j = 4; j >= i; j--) {
            cout << j;
        }
        cout << "\n";
    }
    cout << "\n";

    // Q.6 Custom numeric pattern
    cout << "Q.6 Custom numeric pattern\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        for(int k = 1; k <= 2 * (5 - i); k++) {
            cout << " ";
        }
        for(int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << "\n";
    }
    cout << "\n";

    // Q.7 Custom alphabetic pattern
    cout << "Q.7 Custom alphabetic pattern\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(i == 1 || i == 3) {
                cout << "* ";
            } else if(i == 2) {
                if(j == 1 || j == 5) cout << "* ";
                else cout << "  ";
            } else {
                if(j == 1) {
                    cout << "* ";
                }
            }
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Template class
template <class T>
class Student {
    T id;
    string name;

public:
    // constructor
    Student(T i, string n) {
        id = i;
        name = n;
    }

    void display() {
        cout << "ID: " << id << "  Name: " << name << endl;
    }

    T getId() {
        return id;
    }
};

int main() {
    vector<Student<int>> students;

    int choice, id;
    string name;

    do {
        cout << "\n1.Add  2.Display  3.Remove  4.Search  5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter id: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;

            students.push_back(Student<int>(id, name));
            cout << "Added\n";
        }

        else if (choice == 2) {
            if (students.size() == 0) {
                cout << "No data\n";
            } else {
                for (int i = 0; i < students.size(); i++) {
                    students[i].display();
                }
            }
        }

        else if (choice == 3) {
            cout << "Enter id to remove: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    students.erase(students.begin() + i);
                    cout << "Removed\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Not found\n";
        }

        else if (choice == 4) {
            cout << "Enter id to search: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    students[i].display();
                    found = true;
                }
            }
            if (!found) cout << "Not found\n";
        }

    } while (choice != 5);

    return 0;
}
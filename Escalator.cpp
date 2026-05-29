#include <iostream>
using namespace std;

// Base Class (Inheritance)
class StackBase
{
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;
};

// Derived Class
class Stack : public StackBase
{
private:
    int arr[5];     // Array for stack
    int topIndex;   // Encapsulation

public:
    // Constructor
    Stack()
    {
        topIndex = -1;
    }

    // Push Function
    void push(int value)
    {
        if (topIndex == 4)
        {
            cout << "Stack is Full!" << endl;
        }
        else
        {
            topIndex++;
            arr[topIndex] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop Function
    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << arr[topIndex] << " popped from stack." << endl;
            topIndex--;
        }
    }

    // Top Function
    void top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Top element is: " << arr[topIndex] << endl;
        }
    }

    // Check Empty
    void isEmpty()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty." << endl;
        }
        else
        {
            cout << "Stack is Not Empty." << endl;
        }
    }

    // Check Full
    void isFull()
    {
        if (topIndex == 4)
        {
            cout << "Stack is Full." << endl;
        }
        else
        {
            cout << "Stack is Not Full." << endl;
        }
    }
};

// Main Function
int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.top();
            break;

        case 4:
            s.isEmpty();
            break;

        case 5:
            s.isFull();
            break;

        case 6:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}

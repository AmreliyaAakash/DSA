#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
    Node* head;

public:
    // constructor
    LinkedList() {
        head = NULL;
    }

    // append (insert at end)
    void append(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // display
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // insert at beginning
    void insert_at_beginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // search
    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Not found" << endl;
    }

    // delete node
    void delete_node(int key) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // reverse list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

// main function
int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "List: ";
    list.display();

    list.insert_at_beginning(5);
    cout << "After insert at beginning: ";
    list.display();

    list.search(20);

    list.delete_node(20);
    cout << "After deletion: ";
    list.display();

    list.reverse();
    cout << "After reverse: ";
    list.display();

    return 0;
}
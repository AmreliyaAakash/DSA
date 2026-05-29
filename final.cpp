#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class DataStructure
{
private:
    Node* head;
    int arr[100];
    int n;

public:
    // Constructor
    DataStructure()
    {
        head = NULL;
        n = 0;
    }

    // ================= LINKED LIST =================

    // Insert Node
    void insertNode(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << value << " inserted into linked list.\n";
    }

    // Delete Node
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // Delete first node
        if (temp->data == value)
        {
            head = temp->next;
            delete temp;
            cout << value << " deleted from linked list.\n";
            return;
        }

        while (temp != NULL && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Value not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << value << " deleted from linked list.\n";
    }

    // Display Linked List
    void displayList()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // ================= ARRAY INPUT =================

    void inputArray()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter array elements:\n";

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    // Display Array
    void displayArray()
    {
        cout << "Array: ";

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // ================= MERGE SORT =================

    void merge(int low, int mid, int high)
    {
        int temp[100];

        int i = low;
        int j = mid + 1;
        int k = low;

        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }

        while (j <= high)
        {
            temp[k++] = arr[j++];
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i];
        }
    }

    void mergeSort(int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;

            mergeSort(low, mid);
            mergeSort(mid + 1, high);

            merge(low, mid, high);
        }
    }

    // ================= QUICK SORT =================

    int partition(int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);

            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    // ================= BINARY SEARCH =================

    void binarySearch(int key)
    {
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == key)
            {
                cout << "Element found at position: " << mid + 1 << endl;
                return;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << "Element not found.\n";
    }

    int getSize()
    {
        return n;
    }
};

// ================= MAIN FUNCTION =================

int main()
{
    DataStructure ds;

    int choice, value, key;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Insert in Linked List\n";
        cout << "2. Delete from Linked List\n";
        cout << "3. Display Linked List\n";
        cout << "4. Input Array\n";
        cout << "5. Display Array\n";
        cout << "6. Merge Sort\n";
        cout << "7. Quick Sort\n";
        cout << "8. Binary Search\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            ds.insertNode(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            ds.deleteNode(value);
            break;

        case 3:
            ds.displayList();
            break;

        case 4:
            ds.inputArray();
            break;

        case 5:
            ds.displayArray();
            break;

        case 6:
            ds.mergeSort(0, ds.getSize() - 1);
            cout << "Array sorted using Merge Sort.\n";
            ds.displayArray();
            break;

        case 7:
            ds.quickSort(0, ds.getSize() - 1);
            cout << "Array sorted using Quick Sort.\n";
            ds.displayArray();
            break;

        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            cout << "Note: Array must be sorted.\n";
            ds.binarySearch(key);
            break;

        case 9:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 9);

    return 0;
}

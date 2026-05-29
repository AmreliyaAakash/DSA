#include <iostream>
using namespace std;

class Algorithms
{
private:
    int arr[100], n;

public:
    // Input Array
    void inputArray()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    // Display Array
    void displayArray()
    {
        cout << "Array Elements: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Selection Sort
    void selectionSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;

            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            // Swap
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << "Array sorted using Selection Sort.\n";
        displayArray();
    }

    // Merge Function
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
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }

        while (j <= high)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i];
        }
    }

    // Merge Sort
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

    // Linear Search
    void linearSearch(int key)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                cout << "Element found at position: " << i + 1 << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Element not found.\n";
        }
    }

    // Binary Search
    void binarySearch(int key)
    {
        int low = 0;
        int high = n - 1;
        bool found = false;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == key)
            {
                cout << "Element found at position: " << mid + 1 << endl;
                found = true;
                break;
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

        if (!found)
        {
            cout << "Element not found.\n";
        }
    }

    int getSize()
    {
        return n;
    }
};

// Main Function
int main()
{
    Algorithms obj;
    int choice, key;

    obj.inputArray();

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Array\n";
        cout << "2. Selection Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.displayArray();
            break;

        case 2:
            obj.selectionSort();
            break;

        case 3:
            obj.mergeSort(0, obj.getSize() - 1);
            cout << "Array sorted using Merge Sort.\n";
            obj.displayArray();
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            obj.linearSearch(key);
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> key;
            cout << "Note: Binary Search requires sorted array.\n";
            obj.binarySearch(key);
            break;

        case 6:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}

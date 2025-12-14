#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swapVal(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swapVal(arr[i], arr[j]);
        }
    }
    swapVal(arr[i + 1], arr[high]);
    printArray(arr, n);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

struct MinMax {
    int min, max;
};

MinMax findMinMax(int arr[], int low, int high) {
    MinMax mm, left, right;

    if (low == high) {
        mm.min = arr[low];
        mm.max = arr[low];
        return mm;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            mm.min = arr[low];
            mm.max = arr[high];
        } else {
            mm.min = arr[high];
            mm.max = arr[low];
        }
        return mm;
    }

    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    mm.min = (left.min < right.min) ? left.min : right.min;
    mm.max = (left.max > right.max) ? left.max : right.max;
    return mm;
}

int main() {
    int n, choice;
    int arr[100];
    bool entered = false;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Enter Marks\n";
        cout << "2. Display Marks\n";
        cout << "3. Quick Sort (Show Passes)\n";
        cout << "4. Find Min & Max (Divide & Conquer)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter marks for student " << i + 1 << ": ";
                cin >> arr[i];
            }
            entered = true;
            break;

        case 2:
            if (entered)
                printArray(arr, n);
            else
                cout << "Enter marks first.\n";
            break;

        case 3:
            if (entered) {
                cout << "\nPass-by-pass Quick Sort:\n";
                quickSort(arr, 0, n - 1, n);
                cout << "\nSorted Marks:\n";
                printArray(arr, n);
            } else
                cout << "Enter marks first.\n";
            break;

        case 4:
            if (entered) {
                MinMax mm = findMinMax(arr, 0, n - 1);
                cout << "Minimum marks: " << mm.min << endl;
                cout << "Maximum marks: " << mm.max << endl;
            } else
                cout << "Enter marks first.\n";
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}

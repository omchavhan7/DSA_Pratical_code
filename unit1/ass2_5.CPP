#include <iostream>
using namespace std;

struct Employee {
    string name;
    float height, weight, avg;
};

void input(Employee e[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << " Name: ";
        cin >> e[i].name;
        cout << "Height: ";
        cin >> e[i].height;
        cout << "Weight: ";
        cin >> e[i].weight;
        e[i].avg = (e[i].height + e[i].weight) / 2.0;
    }
}

void display(Employee e[], int n) {
    cout << "\nName\tHeight\tWeight\tAvg\n";
    for (int i = 0; i < n; i++)
        cout << e[i].name << "\t" << e[i].height << "\t" << e[i].weight << "\t" << e[i].avg << endl;
}

int selectionSort(Employee e[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (e[j].avg < e[minIndex].avg)
                minIndex = j;
        if (minIndex != i) {
            swap(e[i], e[minIndex]);
            swaps++;
        }
    }
    return swaps;
}

void merge(Employee e[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Employee L[100], R[100];

    for (int i = 0; i < n1; i++) L[i] = e[l + i];
    for (int j = 0; j < n2; j++) R[j] = e[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        e[k++] = (L[i].avg <= R[j].avg) ? L[i++] : R[j++];

    while (i < n1) e[k++] = L[i++];
    while (j < n2) e[k++] = R[j++];
}

void mergeSort(Employee e[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(e, l, m);
        mergeSort(e, m + 1, r);
        merge(e, l, m, r);
    }
}

int main() {
    Employee E1[100], E2[100];
    int n, choice;
    bool entered = false;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Enter Employee Data\n";
        cout << "2. Display Employees\n";
        cout << "3. Selection Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Conclusion\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter number of employees: ";
            cin >> n;
            input(E1, n);
            for (int i = 0; i < n; i++) E2[i] = E1[i];
            entered = true;
            break;

        case 2:
            if (entered) display(E1, n);
            else cout << "Enter data first.\n";
            break;

        case 3:
            if (entered) {
                for (int i = 0; i < n; i++) E2[i] = E1[i];
                cout << "\nSelection Sort Result:\n";
                int swaps = selectionSort(E2, n);
                display(E2, n);
                cout << "Swaps: " << swaps << endl;
            } else cout << "Enter data first.\n";
            break;

        case 4:
            if (entered) {
                for (int i = 0; i < n; i++) E2[i] = E1[i];
                mergeSort(E2, 0, n - 1);
                cout << "\nMerge Sort Result:\n";
                display(E2, n);
            } else cout << "Enter data first.\n";
            break;

        case 5:
            cout << "\nTime Complexity:\n";
            cout << "Selection Sort: O(n^2)\n";
            cout << "Merge Sort: O(n log n)\n";
            cout << "\nConclusion: Merge Sort takes less time for large lists.\n";
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}

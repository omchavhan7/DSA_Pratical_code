#include <iostream>
using namespace std;

class Matrix {
public:
    int r, c;
    int a[100][100];

    void input() {
        cout << "Enter rows and columns: ";
        cin >> r >> c;
        cout << "Enter elements:\n";
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> a[i][j];
    }

    void display() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
    }
};

Matrix multiplyRowMajor(Matrix A, Matrix B) {
    Matrix R;
    R.r = A.r;
    R.c = B.c;

    for (int i = 0; i < R.r; i++)
        for (int j = 0; j < R.c; j++)
            R.a[i][j] = 0;

    for (int i = 0; i < A.r; i++)
        for (int k = 0; k < A.c; k++)
            for (int j = 0; j < B.c; j++)
                R.a[i][j] += A.a[i][k] * B.a[k][j];

    return R;
}

Matrix multiplyColumnMajor(Matrix A, Matrix B) {
    Matrix R;
    R.r = A.r;
    R.c = B.c;

    for (int i = 0; i < R.r; i++)
        for (int j = 0; j < R.c; j++)
            R.a[i][j] = 0;

    for (int j = 0; j < B.c; j++)
        for (int k = 0; k < A.c; k++)
            for (int i = 0; i < A.r; i++)
                R.a[i][j] += A.a[i][k] * B.a[k][j];

    return R;
}

int main() {
    Matrix A, B, R1, R2;
    int choice;

    do {
        cout << "\n--- MATRIX MENU ---\n";
        cout << "1. Input Matrix A\n";
        cout << "2. Input Matrix B\n";
        cout << "3. Multiply (Row-Major) and Display\n";
        cout << "4. Multiply (Column-Major) and Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            A.input();
            break;

        case 2:
            B.input();
            break;

        case 3:
            if (A.c != B.r)
                cout << "Multiplication not possible.\n";
            else {
                R1 = multiplyRowMajor(A, B);
                cout << "Row-Major Result:\n";
                R1.display();
            }
            break;

        case 4:
            if (A.c != B.r)
                cout << "Multiplication not possible.\n";
            else {
                R2 = multiplyColumnMajor(A, B);
                cout << "Column-Major Result:\n";
                R2.display();
            }
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

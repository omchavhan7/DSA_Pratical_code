#include <iostream>
using namespace std;

struct Triple {
    int row, col, val;
};

class SparseMatrix {
private:
    Triple sp[100], fastT[100];

public:
    void input() {
        int rows, cols, nonZero;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        cout << "Enter number of non-zero elements: ";
        cin >> nonZero;

        sp[0].row = rows;
        sp[0].col = cols;
        sp[0].val = nonZero;

        cout << "\nEnter triplets (row col value):\n";
        for (int i = 1; i <= nonZero; i++)
            cin >> sp[i].row >> sp[i].col >> sp[i].val;
    }

    void display() {
        cout << "\nRow  Col  Val\n";
        for (int i = 0; i <= sp[0].val; i++)
            cout << sp[i].row << "    " << sp[i].col << "    " << sp[i].val << endl;
    }

    void normalTranspose() {
        Triple temp[100];
        int rows = sp[0].row, cols = sp[0].col, n = sp[0].val;

        temp[0].row = cols;
        temp[0].col = rows;
        temp[0].val = n;

        int index = 1;
        for (int c = 0; c < cols; c++)
            for (int i = 1; i <= n; i++)
                if (sp[i].col == c) {
                    temp[index].row = sp[i].col;
                    temp[index].col = sp[i].row;
                    temp[index].val = sp[i].val;
                    index++;
                }

        cout << "\nNormal Transpose:\nRow  Col  Val\n";
        for (int i = 0; i <= n; i++)
            cout << temp[i].row << "    " << temp[i].col << "    " << temp[i].val << endl;
    }

    void fastTranspose() {
        int rows = sp[0].row, cols = sp[0].col, n = sp[0].val;
        int colCount[100] = {0}, startPos[100] = {0};

        fastT[0].row = cols;
        fastT[0].col = rows;
        fastT[0].val = n;

        for (int i = 1; i <= n; i++)
            colCount[sp[i].col]++;

        startPos[0] = 1;
        for (int i = 1; i < cols; i++)
            startPos[i] = startPos[i - 1] + colCount[i - 1];

        for (int i = 1; i <= n; i++) {
            int col = sp[i].col;
            int pos = startPos[col]++;
            fastT[pos].row = sp[i].col;
            fastT[pos].col = sp[i].row;
            fastT[pos].val = sp[i].val;
        }

        cout << "\nFast Transpose:\nRow  Col  Val\n";
        for (int i = 0; i <= n; i++)
            cout << fastT[i].row << "    " << fastT[i].col << "    " << fastT[i].val << endl;
    }
};

int main() {
    SparseMatrix S;
    int choice;

    do {
        cout << "\n===== SPARSE MATRIX MENU =====\n";
        cout << "1. Input Sparse Matrix\n";
        cout << "2. Display Triplet Form\n";
        cout << "3. Normal Transpose\n";
        cout << "4. Fast Transpose\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            S.input();
            break;

        case 2:
            S.display();
            break;

        case 3:
            S.normalTranspose();
            break;

        case 4:
            S.fastTranspose();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

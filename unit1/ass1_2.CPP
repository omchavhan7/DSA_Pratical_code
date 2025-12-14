#include <iostream>
using namespace std;

void generateOddMagicSquare(int n, int magicSquare[][100]) {
    int i = 0, j = n / 2;
    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (magicSquare[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }
}

void generateDoublyEvenMagicSquare(int n, int magicSquare[][100]) {
    int count = 1;
    int total = n * n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = count++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i % 4 == j % 4) || ((i % 4 + j % 4) == 3))
                magicSquare[i][j] = total + 1 - magicSquare[i][j];
}

bool verifyMagicSquare(int n, int magicSquare[][100]) {
    int magicSum = 0;
    for (int j = 0; j < n; j++)
        magicSum += magicSquare[0][j];

    for (int i = 1; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += magicSquare[i][j];
            colSum += magicSquare[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum)
            return false;
    }

    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += magicSquare[i][i];
        diag2 += magicSquare[i][n - i - 1];
    }
    if (diag1 != magicSum || diag2 != magicSum)
        return false;

    return true;
}

void printMatrix(int n, int magicSquare[][100]) {
    if (n == 0) {
        cout << "Magic square not generated.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << magicSquare[i][j] << "\t";
        cout << "\n";
    }
}

void clearSquare(int magicSquare[][100]) {
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            magicSquare[i][j] = 0;
}

int main() {
    int n = 0;
    int magicSquare[100][100] = {0};
    int choice;

    do {
        cout << "\n--- MAGIC SQUARE MENU ---\n";
        cout << "1. Generate Magic Square (Odd Order)\n";
        cout << "2. Generate Magic Square (Doubly Even Order)\n";
        cout << "3. Display Magic Square\n";
        cout << "4. Verify Magic Square\n";
        cout << "5. Clear Magic Square\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter odd order n: ";
            cin >> n;
            if (n % 2 == 1 && n >= 3 && n <= 99) {
                clearSquare(magicSquare);
                generateOddMagicSquare(n, magicSquare);
                cout << "Magic square generated.\n";
            } else
                cout << "Enter a valid odd n (>=3).\n";
            break;

        case 2:
            cout << "Enter doubly-even order n (4,8,12,...): ";
            cin >> n;
            if (n % 4 == 0 && n >= 4 && n <= 100) {
                clearSquare(magicSquare);
                generateDoublyEvenMagicSquare(n, magicSquare);
                cout << "Magic square generated.\n";
            } else
                cout << "Enter valid n (multiple of 4).\n";
            break;

        case 3:
            printMatrix(n, magicSquare);
            break;

        case 4:
            if (n == 0)
                cout << "Magic square not generated.\n";
            else if (verifyMagicSquare(n, magicSquare))
                cout << "Valid magic square.\n";
            else
                cout << "Not a valid magic square.\n";
            break;

        case 5:
            clearSquare(magicSquare);
            n = 0;
            cout << "Magic square cleared.\n";
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

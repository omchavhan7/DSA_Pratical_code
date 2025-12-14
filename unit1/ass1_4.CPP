#include <iostream>
using namespace std;

int main() {
    int mat[20][20], rows, cols;
    int compact[100][3], trans[100][3];
    int nonZero = 0, choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Enter Matrix\n";
        cout << "2. Display Matrix\n";
        cout << "3. Convert to Compact Representation\n";
        cout << "4. Display Compact Representation\n";
        cout << "5. Simple Transpose (Triplet)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "Enter rows and columns: ";
            cin >> rows >> cols;

            cout << "Enter matrix elements:\n";
            nonZero = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cin >> mat[i][j];
                    if (mat[i][j] != 0)
                        nonZero++;
                }
            }
            break;
        }

        case 2: {
            cout << "\nMatrix:\n";
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }

        case 3: {
            compact[0][0] = rows;
            compact[0][1] = cols;
            compact[0][2] = nonZero;

            int k = 1;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (mat[i][j] != 0) {
                        compact[k][0] = i;
                        compact[k][1] = j;
                        compact[k][2] = mat[i][j];
                        k++;
                    }
                }
            }
            cout << "Converted to Compact Form.\n";
            break;
        }

        case 4: {
            cout << "\nCompact Representation (Triplet Form):\n";
            cout << "Row Col Val\n";
            for (int i = 0; i <= nonZero; i++) {
                cout << compact[i][0] << "   "
                     << compact[i][1] << "   "
                     << compact[i][2] << endl;
            }
            break;
        }

        case 5: {
            // simple transpose
            trans[0][0] = compact[0][1];
            trans[0][1] = compact[0][0];
            trans[0][2] = compact[0][2];

            int k = 1;
            for (int c = 0; c < compact[0][1]; c++) {
                for (int i = 1; i <= compact[0][2]; i++) {
                    if (compact[i][1] == c) {
                        trans[k][0] = compact[i][1];
                        trans[k][1] = compact[i][0];
                        trans[k][2] = compact[i][2];
                        k++;
                    }
                }
            }

            cout << "\nSimple Transpose (Triplet):\n";
            cout << "Row Col Val\n";
            for (int i = 0; i <= compact[0][2]; i++) {
                cout << trans[i][0] << "   "
                     << trans[i][1] << "   "
                     << trans[i][2] << endl;
            }
            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

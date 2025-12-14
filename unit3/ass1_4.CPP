#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOpening(char c) {
    return c=='(' || c=='{' || c=='[';
}

bool isClosing(char c) {
    return c==')' || c=='}' || c==']';
}

bool isValidChar(char c) {
    return isOpening(c) || isClosing(c);
}

bool isMatch(char o, char c) {
    return (o=='(' && c==')') ||
           (o=='{' && c=='}') ||
           (o=='[' && c==']');
}

bool isBalanced(const string &s) {
    stack<char> st;
    for(char c : s) {
        if (!isValidChar(c)) return false;
        if (isOpening(c)) st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if (!isMatch(top, c)) return false;
        }
    }
    return st.empty();
}

void showProcess(const string &s) {
    stack<char> st;
    cout << "\nSteps:\n";
    for(char c : s) {
        if (!isValidChar(c)) {
            cout << "Invalid character found: " << c << "\n";
            return;
        }
        if (isOpening(c)) {
            cout << "Push: " << c << "\n";
            st.push(c);
        } else {
            if (st.empty()) {
                cout << "Error: No matching opening bracket for " << c << "\n";
                return;
            }
            char top = st.top();
            st.pop();
            if (isMatch(top, c))
                cout << "Match: " << top << " - " << c << "\n";
            else {
                cout << "Mismatch: " << top << " and " << c << "\n";
                return;
            }
        }
    }

    if (st.empty()) cout << "Final: Balanced\n";
    else cout << "Final: Not Balanced (Extra opening brackets)\n";
}

int countBrackets(const string &s) {
    int count = 0;
    for(char c : s) 
        if (isValidChar(c)) count++;
    return count;
}

int main() {
    int choice;
    string exp;

    do {
        cout << "\n========= ADVANCED PARENTHESIS MENU =========\n";
        cout << "1. Check Balanced Parentheses\n";
        cout << "2. Show Step-by-Step Stack Process\n";
        cout << "3. Count Total Brackets\n";
        cout << "4. Validate Characters\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter parentheses string: ";
                cin >> exp;
                if (isBalanced(exp)) cout << "Balanced\n";
                else cout << "Not Balanced\n";
                break;

            case 2:
                cout << "Enter parentheses string: ";
                cin >> exp;
                showProcess(exp);
                break;

            case 3:
                cout << "Enter parentheses string: ";
                cin >> exp;
                cout << "Total valid brackets: " << countBrackets(exp) << "\n";
                break;

            case 4:
                cout << "Enter parentheses string: ";
                cin >> exp;
                for(char c : exp) {
                    if (!isValidChar(c)) {
                        cout << "Invalid character: " << c << "\n";
                        goto end;
                    }
                }
                cout << "All characters are valid\n";
                end:
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option\n";
        }

    } while(choice != 5);

    return 0;
}

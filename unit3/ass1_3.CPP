#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOpening(char c) {
    return c=='(' || c=='{' || c=='[';
}

bool isClosing(char c) {
    return c==')' || c=='}' || c==']';
}

bool match(char o, char c) {
    return (o=='(' && c==')') ||
           (o=='{' && c=='}') ||
           (o=='[' && c==']');
}

bool isBalanced(const string &s) {
    stack<char> st;
    for(char c : s) {
        if (isOpening(c)) {
            st.push(c);
        } else if (isClosing(c)) {
            if(st.empty() || !match(st.top(), c))
                return false;
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}

void showStack(const string &s) {
    stack<char> st;
    cout << "\nStack Operations:\n";
    for(char c : s) {
        if (isOpening(c)) {
            st.push(c);
            cout << "Push: " << c << "\n";
        } else if (isClosing(c)) {
            if (!st.empty() && match(st.top(), c)) {
                cout << "Pop : " << st.top() << " for " << c << "\n";
                st.pop();
            } else {
                cout << "Error at: " << c << "\n";
            }
        }
    }
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n=========== ADVANCED MENU ===========\n";
        cout << "1. Check Balanced Parentheses\n";
        cout << "2. Show Stack Operations\n";
        cout << "3. Enter Full Line Input\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter string: ";
                cin >> input;
                if (isBalanced(input))
                    cout << "Result: Balanced\n";
                else
                    cout << "Result: Not Balanced\n";
                break;

            case 2:
                cout << "Enter string: ";
                cin >> input;
                showStack(input);
                break;

            case 3:
                cout << "Enter full expression: ";
                getline(cin, input);
                if (isBalanced(input))
                    cout << "Result: Balanced\n";
                else
                    cout << "Result: Not Balanced\n";
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option\n";
        }

    } while(choice != 4);

    return 0;
}

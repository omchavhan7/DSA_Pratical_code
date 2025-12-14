#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/';
}

bool isValidPostfix(const string &exp) {
    int count = 0;
    for(char c : exp) {
        if (isdigit(c)) count++;
        else if (isOperator(c)) count--;
        else return false;
        if (count < 1) return false;
    }
    return count == 1;
}

int evaluatePostfix(const string &exp) {
    stack<int> st;
    for(char c : exp) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch(c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

void showStackProcess(const string &exp) {
    stack<int> st;
    cout << "\nSteps:\n";
    for(char c : exp) {
        if (isdigit(c)) {
            cout << "Push " << c << "\n";
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            cout << "Operate: " << a << " " << c << " " << b << "\n";
            switch(c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    cout << "Final Result: " << st.top() << "\n";
}

string postfixToInfix(const string &exp) {
    stack<string> st;
    for(char c : exp) {
        if (isdigit(c)) st.push(string(1, c));
        else {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push("(" + a + " " + string(1, c) + " " + b + ")");
        }
    }
    return st.top();
}

int precedence(char c) {
    if (c=='*' || c=='/') return 2;
    if (c=='+' || c=='-') return 1;
    return 0;
}

string infixToPostfix(const string &exp) {
    stack<char> st;
    string result;
    for(char c : exp) {
        if (isdigit(c)) result += c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while(!st.empty() && st.top()!='(') {
                result += st.top(); st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c))
                result += st.top(), st.pop();
            st.push(c);
        }
    }
    while(!st.empty()) result += st.top(), st.pop();
    return result;
}

int main() {
    int choice;
    string exp;

    do {
        cout << "\n========== POSTFIX MENU ==========\n";
        cout << "1. Evaluate Postfix\n";
        cout << "2. Check Validity\n";
        cout << "3. Show Step-by-Step Stack Operations\n";
        cout << "4. Convert Postfix to Infix\n";
        cout << "5. Convert Infix to Postfix\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter postfix: ";
                cin >> exp;
                cout << "Result: " << evaluatePostfix(exp) << "\n";
                break;

            case 2:
                cout << "Enter postfix: ";
                cin >> exp;
                if (isValidPostfix(exp))
                    cout << "Valid Postfix\n";
                else
                    cout << "Invalid Postfix\n";
                break;

            case 3:
                cout << "Enter postfix: ";
                cin >> exp;
                showStackProcess(exp);
                break;

            case 4:
                cout << "Enter postfix: ";
                cin >> exp;
                cout << "Infix: " << postfixToInfix(exp) << "\n";
                break;

            case 5:
                cout << "Enter infix: ";
                cin >> exp;
                cout << "Postfix: " << infixToPostfix(exp) << "\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 6);

    return 0;
}

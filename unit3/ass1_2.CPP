#include <iostream>
using namespace std;

#define MAX 30 
#define STACKS 3   

int arr[MAX];
int top[STACKS];
int start[STACKS];
int endIdx[STACKS];

void initialize() {
    int size = MAX / STACKS;
    for(int i = 0; i < STACKS; i++) {
        start[i] = i * size;
        endIdx[i] = start[i] + size - 1;
        top[i] = start[i] - 1;
    }
}

bool isFull(int s) {
    return top[s] == endIdx[s];
}

bool isEmpty(int s) {
    return top[s] < start[s];
}

void push(int s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow\n";
        return;
    }
    top[s]++;
    arr[top[s]] = value;
    cout << "Pushed\n";
}

void pop(int s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << arr[top[s]] << "\n";
    top[s]--;
}

void display(int s) {
    if (isEmpty(s)) {
        cout << "Stack Empty\n";
        return;
    }
    cout << "Stack " << s + 1 << ": ";
    for(int i = top[s]; i >= start[s]; i--)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    initialize();

    int choice, stackNo, value;

    do {
        cout << "\n===== MULTIPLE STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter stack number (1-3): ";
                cin >> stackNo;
                cout << "Enter value: ";
                cin >> value;
                push(stackNo-1, value);
                break;

            case 2:
                cout << "Enter stack number (1-3): ";
                cin >> stackNo;
                pop(stackNo-1);
                break;

            case 3:
                cout << "Enter stack number (1-3): ";
                cin >> stackNo;
                display(stackNo-1);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while(choice != 4);

    return 0;
}

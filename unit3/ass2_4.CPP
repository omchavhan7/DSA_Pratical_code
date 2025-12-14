#include <iostream>
using namespace std;

#define MAX 20

class MultipleQueues {
private:
    int arr[MAX];
    int front1, rear1;
    int front2, rear2;

public:
    MultipleQueues() {
        front1 = rear1 = -1;
        front2 = rear2 = MAX / 2 - 1;
    }

    // Queue 1
    void addQ1(int x) {
        if (rear1 == MAX/2 - 1) {
            cout << "Queue 1 Overflow\n";
            return;
        }
        if (front1 == -1) front1 = 0;
        arr[++rear1] = x;
        cout << "Added to Queue 1\n";
    }

    void deleteQ1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Queue 1 Underflow\n";
            return;
        }
        cout << "Deleted from Queue 1: " << arr[front1++] << "\n";
        if (front1 > rear1) front1 = rear1 = -1;
    }

    void displayQ1() {
        if (front1 == -1) {
            cout << "Queue 1 Empty\n";
            return;
        }
        cout << "Queue 1: ";
        for (int i = front1; i <= rear1; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    // Queue 2
    void addQ2(int x) {
        if (rear2 == MAX - 1) {
            cout << "Queue 2 Overflow\n";
            return;
        }
        if (front2 == MAX/2 - 1) front2++;
        arr[++rear2] = x;
        cout << "Added to Queue 2\n";
    }

    void deleteQ2() {
        if (front2 == MAX/2 - 1 || front2 > rear2) {
            cout << "Queue 2 Underflow\n";
            return;
        }
        cout << "Deleted from Queue 2: " << arr[front2++] << "\n";
        if (front2 > rear2) front2 = rear2 = MAX/2 - 1;
    }

    void displayQ2() {
        if (front2 == MAX/2 - 1) {
            cout << "Queue 2 Empty\n";
            return;
        }
        cout << "Queue 2: ";
        for (int i = front2; i <= rear2; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    MultipleQueues mq;
    int choice, val;

    do {
        cout << "\n===== MULTIPLE QUEUES MENU =====\n";
        cout << "1. Add to Queue 1\n";
        cout << "2. Delete from Queue 1\n";
        cout << "3. Display Queue 1\n";
        cout << "4. Add to Queue 2\n";
        cout << "5. Delete from Queue 2\n";
        cout << "6. Display Queue 2\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                mq.addQ1(val);
                break;
            case 2:
                mq.deleteQ1();
                break;
            case 3:
                mq.displayQ1();
                break;
            case 4:
                cout << "Enter value: ";
                cin >> val;
                mq.addQ2(val);
                break;
            case 5:
                mq.deleteQ2();
                break;
            case 6:
                mq.displayQ2();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}

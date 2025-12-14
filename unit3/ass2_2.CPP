#include <iostream>
#include <string>
using namespace std;

class PizzaParlour {
private:
    int front, rear, size, maxSize;
    string *orders;

public:
    PizzaParlour(int n) {
        maxSize = n;
        orders = new string[n];
        front = rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == maxSize;
    }

    bool isEmpty() {
        return size == 0;
    }

    void placeOrder() {
        if (isFull()) {
            cout << "Order limit reached. Cannot place more orders.\n";
            return;
        }

        string order;
        cout << "Enter pizza order: ";
        cin >> order;

        if (front == -1) front = 0;
        rear = (rear + 1) % maxSize;

        orders[rear] = order;
        size++;

        cout << "Order placed successfully.\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Serving Order: " << orders[front] << "\n";

        front = (front + 1) % maxSize;
        size--;

        if (size == 0) {
            front = rear = -1;
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "\n---- Pending Orders ----\n";

        int i = front;
        for (int count = 0; count < size; count++) {
            cout << orders[i] << "\n";
            i = (i + 1) % maxSize;
        }
    }

    void showStatus() {
        cout << "Available Slots: " << maxSize - size << "\n";
        cout << "Total Orders: " << size << "\n";
    }
};

int main() {
    int n, choice;

    cout << "Enter maximum number of orders for Pizza Parlour: ";
    cin >> n;

    PizzaParlour parlour(n);

    do {
        cout << "\n=========== PIZZA PARLOUR MENU ===========\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Show Queue Status\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: parlour.placeOrder(); break;
            case 2: parlour.serveOrder(); break;
            case 3: parlour.displayOrders(); break;
            case 4: parlour.showStatus(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 5);

    return 0;
}

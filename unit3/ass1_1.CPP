#include <iostream>
#include <limits>
using namespace std;

struct Node {
    string name;
    int price;
    Node* next;
};

class StockStack {
private:
    Node* top;
    int count;
    int maxPrice;
    int minPrice;
    long long sum;

   
    void recomputeStats() {
        maxPrice = INT_MIN;
        minPrice = INT_MAX;
        sum = 0;

        Node* temp = top;
        while (temp != NULL) {
            if (temp->price > maxPrice) maxPrice = temp->price;
            if (temp->price < minPrice) minPrice = temp->price;
            sum += temp->price;
            temp = temp->next;
        }
    }

public:
    StockStack() {
        top = NULL;
        count = 0;
        maxPrice = INT_MIN;
        minPrice = INT_MAX;
        sum = 0;
    }

    void record(string name, int price) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->price = price;

        newNode->next = top;
        top = newNode;

        count++;
        sum += price;

        if (price > maxPrice) maxPrice = price;
        if (price < minPrice) minPrice = price;

        cout << "Recorded: " << name << " - " << price << endl;
    }

    int removePrice() {
        if (isEmpty()) {
            cout << "No stock entries to remove!\n";
            return -1;
        }

        string removedName = top->name;
        int removedPrice = top->price;

        Node* temp = top;
        top = top->next;
        delete temp;

        count--;

        if (count == 0) {
            maxPrice = INT_MIN;
            minPrice = INT_MAX;
            sum = 0;
        }
        else {

            if (removedPrice == maxPrice || removedPrice == minPrice) {
                recomputeStats();
            }
            else {
                sum -= removedPrice;
            }
        }

        cout << "Removed: " << removedName << " - " << removedPrice << endl;
        return removedPrice;
    }

    void latest() {
        if (isEmpty()) {
            cout << "No stock entries recorded!\n";
            return;
        }
        cout << "Latest Stock: " << top->name << " - " << top->price << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "No stock entries.\n";
            return;
        }

        Node* temp = top;
        cout << "\nAll Stocks (Latest → Oldest):\n";
        while (temp != NULL) {
            cout << temp->name << " - " << temp->price << endl;
            temp = temp->next;
        }
    }

    void showStats() {
        if (isEmpty()) {
            cout << "No data available.\n";
            return;
        }

        cout << "\n--- Stock Price Statistics ---\n";
        cout << "Total Entries : " << count << endl;
        cout << "Latest Stock  : " << top->name << " - " << top->price << endl;
        cout << "Highest Price : " << maxPrice << endl;
        cout << "Lowest Price  : " << minPrice << endl;
        cout << "Average Price : " << (double)sum / count << endl;
    }
};

int main() {
    StockStack s;
    int choice, price;
    string name;

    while (true) {
        cout << "\n========= ADVANCED STOCK PRICE TRACKER =========\n";
        cout << "1. Record new stock (name + price)\n";
        cout << "2. Remove latest stock entry\n";
        cout << "3. Show latest stock\n";
        cout << "4. Display all stocks\n";
        cout << "5. Show statistics (min, max, avg)\n";
        cout << "6. Check if empty\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter stock name: ";
                cin >> name;
                cout << "Enter price: ";
                cin >> price;
                s.record(name, price);
                break;

            case 2:
                s.removePrice();
                break;

            case 3:
                s.latest();
                break;

            case 4:
                s.displayAll();
                break;

            case 5:
                s.showStats();
                break;

            case 6:
                if (s.isEmpty()) cout << "Stack is empty.\n";
                else cout << "Stock entries available.\n";
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

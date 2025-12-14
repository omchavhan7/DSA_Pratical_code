#include <iostream>
#include <string>
using namespace std;

class GNode {
public:
    int tag;
    string atom;
    GNode* down;
    GNode* next;

    GNode(int t, string a = "") {
        tag = t;
        atom = a;
        down = next = NULL;
    }
};

class GList {
public:
    GNode* head;

    GList() {
        head = NULL;
    }

    GNode* createSet() {
        string token;
        cin >> token;

        if (token == "0") return NULL;

        GNode* start = NULL;
        GNode* last = NULL;

        while (token != "0") {
            GNode* temp;

            if (token == "{") {
                temp = new GNode(1);
                temp->down = createSet();
            }
            else if (token == "}") {
                return start;
            }
            else {
                temp = new GNode(0, token);
            }

            if (!start)
                start = temp;
            else
                last->next = temp;

            last = temp;

            cin >> token;
        }
        return start;
    }

    void display(GNode* node) {
        cout << "{ ";
        while (node) {
            if (node->tag == 0)
                cout << node->atom << " ";
            else {
                display(node->down);
                cout << " ";
            }
            node = node->next;
        }
        cout << "}";
    }
};

int main() {
    GList gl;
    int ch;

    do {
        cout << "\n--- GLL Menu ---\n";
        cout << "1. Create Generalized List\n";
        cout << "2. Display Generalized List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter set using { } and 0 to end:\n";
            gl.head = gl.createSet();
            break;

        case 2:
            if (!gl.head)
                cout << "List empty\n";
            else {
                cout << "\nGLL: ";
                gl.display(gl.head);
                cout << "\n";
            }
            break;

        case 3:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid\n";
        }
    } while (ch != 3);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int,int>>> adj; // (neighbor, weight)

public:
    Graph(int vertices = 0) {
        V = vertices;
        adj.resize(V);
    }

    void createGraph() {
        cout << "Enter number of vertices: ";
        cin >> V;
        adj.clear();
        adj.resize(V);

        int E;
        cout << "Enter number of edges: ";
        cin >> E;

        cout << "Enter edges as: u v weight\n";
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
        cout << "Graph created successfully.\n";
    }

    void addEdge(int u, int v, int w) {
        if (u >= V || v >= V) {
            cout << "Invalid vertex!\n";
            return;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    void displayGraph() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto &p : adj[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << "\n";
        }
    }

    void primMST() {
        if (V == 0) {
            cout << "Graph not created.\n";
            return;
        }

        vector<int> key(V, 1e9);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        int start;
        cout << "Enter starting vertex: ";
        cin >> start;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto &p : adj[u]) {
                int v = p.first;
                int weight = p.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
        int totalCost = 0;

        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " -- " << i
                     << " (Weight: " << key[i] << ")\n";
                totalCost += key[i];
            }
        }

        cout << "\nTotal Cost of MST = " << totalCost << "\n";
    }
};

int main() {
    Graph g;
    int choice;

    do {
        cout << "\n========== PRIM'S ALGORITHM MENU ==========\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Graph (Adjacency List)\n";
        cout << "3. Find MST using Prim's Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: g.createGraph(); break;
            case 2: g.displayGraph(); break;
            case 3: g.primMST(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 4);

    return 0;
}

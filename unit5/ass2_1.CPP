#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u, v, w;
};

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (rank[a] < rank[b]) parent[a] = b;
        else if (rank[b] < rank[a]) parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
        return true;
    }
};

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices = 0) {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    void createGraph() {
        cout << "Enter number of vertices: ";
        cin >> V;

        adj.clear();
        adj.resize(V, vector<int>(V, 0));

        cout << "Enter adjacency matrix (0 for no edge):\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cin >> adj[i][j];
            }
        }
        cout << "Graph created successfully.\n";
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void kruskalMST() {
        if (V == 0) {
            cout << "Graph not created.\n";
            return;
        }

        vector<Edge> edges;

        // Extract edges from adjacency matrix (undirected)
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (adj[i][j] != 0) {
                    edges.push_back({i, j, adj[i][j]});
                }
            }
        }

        sort(edges.begin(), edges.end(),
            [](Edge &a, Edge &b) { return a.w < b.w; });

        DSU dsu(V);

        cout << "\nMinimum Spanning Tree (Kruskal’s Algorithm):\n";

        int totalCost = 0;
        int edgesUsed = 0;

        for (auto &e : edges) {
            if (dsu.unite(e.u, e.v)) {
                cout << e.u << " -- " << e.v << " (Weight: " << e.w << ")\n";
                totalCost += e.w;
                edgesUsed++;

                if (edgesUsed == V - 1) break;
            }
        }

        cout << "\nTotal Cost of MST = " << totalCost << "\n";
    }
};

int main() {
    Graph g;
    int choice;

    do {
        cout << "\n========== KRUSKAL’S ALGORITHM MENU ==========\n";
        cout << "1. Create Graph (Adjacency Matrix)\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Find MST using Kruskal’s Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.createGraph();
                break;
            case 2:
                g.displayMatrix();
                break;
            case 3:
                g.kruskalMST();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

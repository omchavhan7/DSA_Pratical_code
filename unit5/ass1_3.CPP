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

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<Edge> edges;

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
        edges.clear();

        int E;
        cout << "Enter number of edges: ";
        cin >> E;

        cout << "Enter edges as: u v weight (vertices from 1 to " << V << ")\n";

        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            // Convert 1-based to 0-based
            u--; 
            v--;

            // Validate input
            if (u < 0 || u >= V || v < 0 || v >= V) {
                cout << "Invalid vertex number! Please re-enter this edge.\n";
                i--;
                continue;
            }

            addEdge(u, v, w);
        }

        cout << "Graph created successfully.\n";
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    void displayGraph() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i + 1 << " -> ";  // print 1-based
            for (auto &p : adj[i]) {
                cout << "(" << p.first + 1 << ", " << p.second << ") ";
            }
            cout << "\n";
        }
    }

    void kruskalMST() {
        if (V == 0) {
            cout << "Graph not created.\n";
            return;
        }

        sort(edges.begin(), edges.end(),
             [](Edge &a, Edge &b) { return a.w < b.w; });

        DSU dsu(V);

        cout << "\nMinimum Spanning Tree (Kruskal's Algorithm):\n";

        int totalCost = 0, used = 0;

        for (auto &e : edges) {
            if (dsu.unite(e.u, e.v)) {
                cout << (e.u + 1) << " -- " << (e.v + 1)
                     << "  (Weight: " << e.w << ")\n";
                totalCost += e.w;
                used++;
                if (used == V - 1)
                    break;
            }
        }

        cout << "\nTotal Cost of MST = " << totalCost << "\n";
    }
};

int main() {
    Graph g;
    int choice;

    do {
        cout << "\n======= KRUSKAL'S ALGORITHM MENU =======\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Graph (Adjacency List)\n";
        cout << "3. Generate MST using Kruskal's Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.createGraph();
            break;
        case 2:
            g.displayGraph();
            break;
        case 3:
            g.kruskalMST();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

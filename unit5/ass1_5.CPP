#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices = 0) {
        V = vertices;
        adj.resize(V);
    }

    void acceptGraph() {
        cout << "Enter number of vertices: ";
        cin >> V;

        adj.clear();
        adj.resize(V);

        int E;
        cout << "Enter number of edges: ";
        cin >> E;

        cout << "Enter edges as (u v) from 1 to " << V << ":\n";

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;

            // Convert to 0-based index
            u--;  
            v--;

            // Validate
            if (u < 0 || u >= V || v < 0 || v >= V) {
                cout << "Invalid edge! Please re-enter.\n";
                i--;  
                continue;
            }

            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }

        cout << "Graph created successfully.\n";
    }

    void displayGraph() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << (i + 1) << " -> ";
            for (int nbr : adj[i])
                cout << (nbr + 1) << " ";
            cout << "\n";
        }
    }

    void bfs(int start) {
        start--;  // Convert to 0-based

        if (start < 0 || start >= V) {
            cout << "Invalid start vertex!\n";
            return;
        }

        vector<int> visited(V, 0);
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << (node + 1) << " ";

            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        cout << "\n";
    }

    void dfsUtil(int node, vector<int>& visited) {
        visited[node] = 1;
        cout << (node + 1) << " ";

        for (int nbr : adj[node]) {
            if (!visited[nbr])
                dfsUtil(nbr, visited);
        }
    }

    void dfs(int start) {
        start--; // Convert to 0-based

        if (start < 0 || start >= V) {
            cout << "Invalid start vertex!\n";
            return;
        }

        vector<int> visited(V, 0);
        cout << "DFS Traversal: ";
        dfsUtil(start, visited);
        cout << "\n";
    }
};

int main() {
    Graph g;
    int choice, start;

    do {
        cout << "\n========== GRAPH MENU ==========\n";
        cout << "1. Accept Graph (Adjacency List)\n";
        cout << "2. Display Graph\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.acceptGraph();
                break;

            case 2:
                g.displayGraph();
                break;

            case 3:
                cout << "Enter starting vertex (1 to V): ";
                cin >> start;
                g.bfs(start);
                break;

            case 4:
                cout << "Enter starting vertex (1 to V): ";
                cin >> start;
                g.dfs(start);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}

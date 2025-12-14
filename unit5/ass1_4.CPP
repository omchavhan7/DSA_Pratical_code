#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices = 0)
    {
        V = vertices;
        adj.resize(V);
    }

    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> V;

        adj.clear();
        adj.resize(V);

        int E;
        cout << "Enter number of edges: ";
        cin >> E;

        cout << "Enter edges in format: u v weight (vertices from 1 to " << V << ")\n";

        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            // Convert to 0-based
            u--;  
            v--;

            // Validate indices
            if (u < 0 || u >= V || v < 0 || v >= V)
            {
                cout << "Invalid vertex number! Please re-enter this edge.\n";
                i--;
                continue;
            }

            addEdge(u, v, w);
        }

        cout << "Graph created successfully.\n";
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});  // Directed graph
    }

    void displayGraph()
    {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++)
        {
            cout << (i + 1) << " -> ";
            for (auto &p : adj[i])
            {
                cout << "(" << p.first + 1 << ", " << p.second << ") ";
            }
            cout << "\n";
        }
    }

    void dijkstra(int src, int dest)
    {
        src--;
        dest--;

        if (src < 0 || src >= V || dest < 0 || dest >= V)
        {
            cout << "Invalid source or destination!\n";
            return;
        }

        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto &edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nShortest Distance = " << dist[dest] << "\n";

        cout << "Shortest Path: ";
        printPath(parent, dest);
        cout << "\n";
    }

    void printPath(vector<int> &parent, int node)
    {
        if (node == -1)
            return;
        printPath(parent, parent[node]);
        cout << (node + 1) << " ";  // Convert back to 1-based
    }
};

int main()
{
    Graph g;
    int choice;

    do
    {
        cout << "\n=========== DIJKSTRA MENU ===========\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Graph\n";
        cout << "3. Find Shortest Distance (Dijkstra)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayGraph();
            break;

        case 3:
        {
            int src, dest;
            cout << "Enter source vertex (1 to n): ";
            cin >> src;
            cout << "Enter destination vertex (1 to n): ";
            cin >> dest;
            g.dijkstra(src, dest);
            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

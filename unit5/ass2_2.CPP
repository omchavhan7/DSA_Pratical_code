#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices = 0)
    {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> V;

        adj.clear();
        adj.resize(V, vector<int>(V, 0));

        cout << "Enter adjacency matrix (0 means NO edge):\n";
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                cin >> adj[i][j];

        cout << "Graph created successfully.\n";
    }

    void displayMatrix()
    {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << adj[i][j] << " ";
            cout << "\n";
        }
    }

    int minDistance(vector<int> &dist, vector<bool> &visited)
    {
        int minVal = INT_MAX, minIndex = -1;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minVal)
            {
                minVal = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void printPath(vector<int> &parent, int j)
    {
        if (j == -1)
            return;
        printPath(parent, parent[j]);
        cout << (j + 1) << " "; // convert back to 1-based
    }

    void dijkstra(int src, int dest)
    {
        // Convert to 0-based indexing
        src--;
        dest--;

        // Validate input
        if (src < 0 || src >= V || dest < 0 || dest >= V)
        {
            cout << "Invalid source or destination node!\n";
            return;
        }

        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int u = minDistance(dist, visited);
            if (u == -1) break;

            visited[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (!visited[v] && adj[u][v] != 0 &&
                    dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "\nShortest Distance from " << (src + 1)
             << " to " << (dest + 1)
             << " = " << dist[dest] << "\n";

        cout << "Path: ";
        printPath(parent, dest);
        cout << "\n";
    }
};

int main()
{
    Graph g;
    int choice;

    do
    {
        cout << "\n========== DIJKSTRA MENU ==========\n";
        cout << "1. Create Graph (Adjacency Matrix)\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Find Shortest Path (Dijkstra)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayMatrix();
            break;

        case 3:
        {
            int src, dest;
            cout << "Enter Source Node (1 to n): ";
            cin >> src;
            cout << "Enter Destination Node (1 to n): ";
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

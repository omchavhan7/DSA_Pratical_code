#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
private:
    int n;
    vector<vector<int>> adj;
    vector<int> visited;

public:
    Graph(int vertices)
    {
        n = vertices;
        adj.resize(n, vector<int>(n, 0));
        visited.resize(n, 0);
    }

    void acceptGraph()
    {
        int edges, u, v, choice;

        cout << "1. Directed Graph\n2. Undirected Graph\nChoose type: ";
        cin >> choice;

        cout << "Enter number of edges: ";
        cin >> edges;

        for (int i = 0; i < edges; i++)
        {
            cout << "Enter edge (u v) starting from 1 to " << n << ": ";
            cin >> u >> v;

            u--;
            v--;

            if (u < 0 || u >= n || v < 0 || v >= n)
            {
                cout << "Invalid vertex! Enter between 1 and " << n << ". Try again.\n";
                i--;
                continue;
            }

            adj[u][v] = 1;
            if (choice == 2)
                adj[v][u] = 1;
        }

        cout << "Graph input complete.\n";
    }

    void showAdjMatrix()
    {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

   
    void displayGraph()
    {
        cout << "\nGraph Representation (Adjacency List):\n";
        for (int i = 0; i < n; i++)
        {
            cout << (i + 1) << " -> ";
            bool hasEdges = false;

            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] == 1)
                {
                    cout << (j + 1) << " ";
                    hasEdges = true;
                }
            }

            if (!hasEdges)
                cout << "No Connections";

            cout << "\n";
        }
    }

    void bfs(int start)
    {
        fill(visited.begin(), visited.end(), 0);
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << (node + 1) << " ";

            for (int i = 0; i < n; i++)
            {
                if (adj[node][i] == 1 && !visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        cout << "\n";
    }

    void dfsUtil(int node)
    {
        visited[node] = 1;
        cout << (node + 1) << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                dfsUtil(i);
            }
        }
    }

    void dfs(int start)
    {
        fill(visited.begin(), visited.end(), 0);
        cout << "DFS Traversal: ";
        dfsUtil(start);
        cout << "\n";
    }
};

int main()
{
    int n, choice, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    do
    {
        cout << "\n=========== GRAPH MENU ===========\n";
        cout << "1. Accept Graph (Adjacency Matrix)\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Display Graph (Adjacency List)\n";   
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.acceptGraph();
            break;

        case 2:
            g.showAdjMatrix();
            break;

        case 3:
            cout << "Enter start vertex (1 to " << n << "): ";
            cin >> start;
            start--;
            g.bfs(start);
            break;

        case 4:
            cout << "Enter start vertex (1 to " << n << "): ";
            cin >> start;
            start--;
            g.dfs(start);
            break;

        case 5:
            g.displayGraph();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}

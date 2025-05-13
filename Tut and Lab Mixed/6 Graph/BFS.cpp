#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_VERTICES = 100;

// Graph class
class Graph
{
private:
    int vertices;
    vector<int> adjList[MAX_VERTICES];

public:
    Graph()
    {
        vertices = 0;
    }

    void addVertex()
    {
        if (vertices >= MAX_VERTICES)
        {
            cout << "Maximum vertex limit reached.\n";
            return;
        }
        vertices++;
    }

    void addEdge(int u, int v)
    {
        if (u >= vertices || v >= vertices || u < 0 || v < 0)
        {
            cout << "Invalid edge (" << u << ", " << v << ").\n";
            return;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    void displayGraph()
    {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i])
                cout << neighbor << " ";
            cout << endl;
        }
    }

    void bfs(int start)
    {
        if (start >= vertices || start < 0)
        {
            cout << "Invalid starting vertex.\n";
            return;
        }

        bool visited[MAX_VERTICES] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

void displayMenu()
{
    cout << "1. Add Vertex\n";
    cout << "2. Add Edge\n";
    cout << "3. Display Graph\n";
    cout << "4. BFS Traversal\n";
    cout << "0. Exit\n";
}

int main()
{
    Graph g;
    int choice, u, v, start;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.addVertex();
            cout << "Vertex added.\n";
            break;
        case 2:
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            g.addEdge(u, v);
            break;
        case 3:
            g.displayGraph();
            break;
        case 4:
            cout << "Enter starting vertex: ";
            cin >> start;
            g.bfs(start);
            break;
        case 0:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
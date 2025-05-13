#include <iostream>
#include <vector>
#include <stack>
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

    void dfs(int start)
    {
        if (start >= vertices || start < 0)
        {
            cout << "Invalid starting vertex.\n";
            return;
        }

        bool visited[MAX_VERTICES] = {false};
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal: ";

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (!visited[current])
            {
                visited[current] = true;
                cout << current << " ";

                // Push unvisited neighbors
                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it)
                    if (!visited[*it])
                        s.push(*it);
            }
        }
        cout << endl;
    }
};

void displayMenu()
{
    cout << "\n=== DFS MENU ===\n";
    cout << "1. Add Vertex\n";
    cout << "2. Add Edge\n";
    cout << "3. Display Graph\n";
    cout << "4. DFS Traversal\n";
    cout << "0. Exit\n";
}

int main()
{
    Graph g;
    int choice, u, v, start;

    cout << "=== DFS Traversal in Graph ===\n";

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
            g.dfs(start);
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
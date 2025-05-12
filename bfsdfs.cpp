#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v)
    {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void BFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from vertex " << start << ": ";

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int adj : adjList[vertex])
            {
                if (!visited[adj])
                {
                    visited[adj] = true;
                    q.push(adj);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int adj : adjList[vertex])
        {
            if (!visited[adj])
            {
                DFSUtil(adj, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(vertices, false);
        cout << "DFS traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main()
{
    int v, e, start;

    cout << "Enter number of vertices: ";
    cin >> v;
    if (v <= 0)
    {
        cout << "Number of vertices must be positive!" << endl;
        return 1;
    }

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;
    if (e < 0)
    {
        cout << "Number of edges cannot be negative!" << endl;
        return 1;
    }

    cout << "Enter " << e << " edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        if (v1 < 0 || v1 >= v || v2 < 0 || v2 >= v)
        {
            cout << "Invalid vertex! Vertices should be between 0 and " << v - 1 << endl;
            i--;
            continue;
        }
        g.addEdge(v1, v2);
    }

    cout << "Enter starting vertex (0 to " << v - 1 << "): ";
    cin >> start;
    if (start < 0 || start >= v)
    {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }

    cout << "\nTraversals:" << endl;
    g.BFS(start);
    g.DFS(start);

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

// Class to represent a graph using an adjacency list
class Graph {
    int numVertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    // Function to add an edge to the graph (Undirected by default)
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Remove this line for a Directed Graph
    }

    // Helper function for DFS tracking visited nodes
    void DFSRecursive(int vertex, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[vertex] = true;
        cout << vertex << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSRecursive(neighbor, visited);
            }
        }
    }

    // Main DFS function that initializes the visited array
    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "DFS Traversal starting from vertex " << startVertex << ":\n";
        DFSRecursive(startVertex, visited);
        cout << endl;
    }
};

int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // Run DFS starting from vertex 0
    g.DFS(0);

    return 0;
}

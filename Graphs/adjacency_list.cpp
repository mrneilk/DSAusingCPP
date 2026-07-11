#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    // An array/vector of vectors. Each index represents a vertex, 
    // and the vector at that index holds its neighbors.
    std::vector<std::vector<int>> adjList;

public:
    // Initialize the graph with a fixed number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    // Add an edge (for an undirected graph)
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Remove this line if the graph is Directed
    }

    // Print the adjacency list
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ":";
            for (int neighbor : adjList[i]) {
                std::cout << " -> " << neighbor;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create a graph with 4 vertices (0, 1, 2, 3)
    Graph g(4);

    // Recreate our previous example graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    // Print the representation
    g.printGraph();

    return 0;
}

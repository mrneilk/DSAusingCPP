#include <iostream>
#include <vector>
#include <list>
#include <string>

class SystemGraph {
private:
    int numNodes;
    // Each index in the vector represents a node. 
    // The list at that index contains its neighbors (edges).
    std::vector<std::list<int>> adjList;
    std::vector<std::string> nodeNames;

public:
    SystemGraph(int nodes) : numNodes(nodes) {
        adjList.resize(nodes);
        nodeNames.resize(nodes);
    }

    void setNodeName(int id, std::string name) {
        if (id < numNodes) nodeNames[id] = name;
    }

    // Add an edge (dependency) from source to destination
    void addDependency(int src, int dest) {
        adjList[src].push_back(dest);
        // For an undirected graph, you would also add: adjList[dest].push_back(src);
    }

    void printGraph() {
        std::cout << "--- System Dependency Graph ---\n";
        for (int i = 0; i < numNodes; ++i) {
            std::cout << "[" << nodeNames[i] << "] relies on: ";
            for (int neighbor : adjList[i]) {
                std::cout << nodeNames[neighbor] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    // Let's model a simple 4-part system architecture
    SystemGraph network(4);

    network.setNodeName(0, "WebUI");
    network.setNodeName(1, "AuthService");
    network.setNodeName(2, "Database");
    network.setNodeName(3, "LoggingService");

    // Define dependencies
    network.addDependency(0, 1); // WebUI depends on Auth
    network.addDependency(0, 3); // WebUI depends on Logging
    network.addDependency(1, 2); // Auth depends on Database
    network.addDependency(2, 3); // Database depends on Logging

    network.printGraph();

    return 0;
}

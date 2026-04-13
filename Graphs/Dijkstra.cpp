#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Pair of (distance, node)
typedef pair<int, int> iPair;

class Graph {
    int V; // Number of vertices
    vector<vector<iPair>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    // Dijkstra's Algorithm
    void dijkstra(int src) {
        // Priority queue to store {distance, node}, ordered by smallest distance
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        // Vector for distances, initialized to infinity
        vector<int> dist(V, INT_MAX);

        // Insert source itself in priority queue and initialize its distance as 0
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            // Extract the vertex with the minimum distance
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            // Optimization: Skip if we've already found a better path
            if (d > dist[u]) continue;

            // Traverse neighbors
            for (auto const& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print results
        cout << "Vertex \t Distance from Source (" << src << ")" << endl;
        for (int i = 0; i < V; ++i)
            cout << i << " \t\t " << dist[i] << endl;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 9);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    g.dijkstra(0);

    return 0;
}

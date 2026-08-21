#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>

class ConsistentHashRing {
private:
    // The "Ring" maps a hash value (unsigned int) to a Server Name (string)
    std::map<size_t, std::string> ring;
    int virtualNodes;
    std::hash<std::string> hashFn; // Standard string hasher

public:
    ConsistentHashRing(int vNodes) : virtualNodes(vNodes) {}

    // Add a server to the ring with multiple virtual nodes
    void addServer(const std::string& serverName) {
        for (int i = 0; i < virtualNodes; ++i) {
            size_t hash = hashFn(serverName + ":" + std::to_string(i));
            ring[hash] = serverName;
        }
    }

    // Remove a server and all its virtual nodes
    void removeServer(const std::string& serverName) {
        for (int i = 0; i < virtualNodes; ++i) {
            size_t hash = hashFn(serverName + ":" + std::to_string(i));
            ring.erase(hash);
        }
    }

    // Find which server is responsible for a given key
    std::string getServer(const std::string& key) {
        if (ring.empty()) return "No servers available";

        size_t hash = hashFn(key);
        
        // lower_bound finds the first element >= the hash (moving clockwise)
        auto it = ring.lower_bound(hash);

        // If we reach the end of the map, wrap around to the beginning
        if (it == ring.end()) {
            return ring.begin()->second;
        }

        return it->second;
    }
};
//main
int main() {
    ConsistentHashRing myCluster(3); // 3 virtual nodes per server

    myCluster.addServer("Server_A");
    myCluster.addServer("Server_B");
    myCluster.addServer("Server_C");

    std::string dataKey = "User_Session_99";
    std::cout << "Data key [" << dataKey << "] is stored on: " 
              << myCluster.getServer(dataKey) << std::endl;

    return 0;
}

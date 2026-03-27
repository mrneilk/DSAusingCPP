#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>

struct Flight {
    std::string destination;
    int price;
};

class TravelGraph {
    // Map City Name -> List of (Destination City, Price)
    std::unordered_map<std::string, std::list<Flight>> adjList;

public:
    // Add a one-way flight
    void addFlight(std::string from, std::string to, int cost) {
        adjList[from].push_back({to, cost});
    }

    void displayRoutes() {
        for (auto const& [city, flights] : adjList) {
            std::cout << "Departing from " << city << ":\n";
            for (auto const& f : flights) {
                std::cout << "  -> " << f.destination << " (Price: $" << f.price << ")\n";
            }
        }
    }

    void findDirectFlights(std::string city) {
        if (adjList.find(city) == adjList.end()) {
            std::cout << "No flights found from " << city << "\n";
            return;
        }
        std::cout << "Direct flights from " << city << " available.\n";
    }
};

int main() {
    TravelGraph airportSystem;

    // Building the network
    airportSystem.addFlight("New York", "London", 800);
    airportSystem.addFlight("New York", "Paris", 750);
    airportSystem.addFlight("London", "Tokyo", 1200);
    airportSystem.addFlight("Tokyo", "New York", 1100);
    airportSystem.addFlight("Paris", "London", 200);

    airportSystem.displayRoutes();

    return 0;
}

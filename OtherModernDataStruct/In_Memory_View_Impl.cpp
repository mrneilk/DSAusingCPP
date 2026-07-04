#include <iostream>
#include <vector>
// error: 'span' is not a member of 'std'; did you mean 'std::span'?
#include <span>
#include <algorithm>

// A simple structure representing a Data Record
struct Record {
    int id;
    double value;
};

void processView(std::span<Record> view) {
    for (const auto& r : view) {
        std::cout << "ID: " << r.id << " Value: " << r.value << "\n";
    }
}

int main() {
    // The "Source of Truth" in memory
    std::vector<Record> database = {
        {1, 10.5}, {2, 20.0}, {3, 35.2}, {4, 40.8}, {5, 55.0}
    };

    // Create a 'View' of only the middle three elements
    // This is zero-copy; it only stores a pointer and a length.
    std::span<Record> middleView(database.data() + 1, 3);

    std::cout << "Processing In-Memory View:\n";
    processView(middleView);

    return 0;
}

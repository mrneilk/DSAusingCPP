#include <iostream>
#include <vector>

int main() {
    // Declaration: vector<dataType> name;
    std::vector<int> numbers = {10, 20, 30};

    // Adding elements
    numbers.push_back(40); 

    // Accessing elements (same as arrays)
    std::cout << "First element: " << numbers[0] << std::endl;

    // Removing the last element
    numbers.pop_back();

    return 0;
}

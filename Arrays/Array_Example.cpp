#include <iostream>
#include <vector>   // You must include this header
#include <string>

int main() {
    // 1. Declaration: Notice we don't have to give it a size!
    std::vector<std::string> groceryList;

    // 2. Adding items: The .push_back() method adds to the end
    groceryList.push_back("Milk");
    groceryList.push_back("Eggs");
    groceryList.push_back("Bread");

    // 3. Accessing: Works exactly like an array
    std::cout << "First item: " << groceryList[0] << std::endl;

    // 4. Updating: Still super fast
    groceryList[1] = "Organic Eggs";

    // 5. Removing: Let's remove the last item ("Bread")
    groceryList.pop_back();

    // 6. Dynamic Size: The vector knows how big it is
    std::cout << "Items to buy: " << groceryList.size() << std::endl;

    return 0;
}

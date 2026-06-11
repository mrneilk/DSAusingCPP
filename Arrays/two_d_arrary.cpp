#include <vector>
#include <iostream>

int main() {
    // Creating a 3x3 vector initialized with 0
    std::vector<std::vector<int>> vec(3, std::vector<int>(3, 0));
    
    vec[0][0] = 10;
    
    // Getting dimensions safely
    int rows = vec.size();
    int cols = vec[0].size();
    
    std::cout << "Element at 0,0: " << vec[0][0];
}

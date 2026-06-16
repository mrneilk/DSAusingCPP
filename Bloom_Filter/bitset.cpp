#include <iostream>
#include <bitset>

int main() {
    // 1. Default initialization (all bits set to 0)
    std::bitset<8> b1; // 00000000

    // 2. Initialization from an unsigned integer
    std::bitset<8> b2(42); // 00101010 (binary of 42)

    // 3. Initialization from a string
    std::bitset<8> b3("1100"); // 00001100 (padded with leading zeros)
}

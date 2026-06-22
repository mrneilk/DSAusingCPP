#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void countWithFrequencyArray(const std::string& str) {
    // There are 256 possible ASCII characters
    // Initialize all counts to 0
    std::vector<int> freq(256, 0);

    // "Hash" each character by using its ASCII value as the index
    for (char ch : str) {
        freq[static_cast<unsigned char>(ch)]++;
    }

    std::cout << "--- Count using Frequency Array (ASCII) ---\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            std::cout << "'" << static_cast<char>(i) << "' : " << freq[i] << "\n";
        }
    }
}

void countWithHashMap(const std::string& str) {
    // A hash map handles the hashing internally
    std::unordered_map<char, int> charMap;

    for (char ch : str) {
        charMap[ch]++;
    }

    std::cout << "\n--- Count using std::unordered_map ---\n";
    for (const auto& pair : charMap) {
        std::cout << "'" << pair.first << "' : " << pair.second << "\n";
    }
}

int main() {
    std::string text = "hello world!";
    
    std::cout << "Original String: " << text << "\n\n";
    
    countWithFrequencyArray(text);
    countWithHashMap(text);

    return 0;
}

// Bloom Filters
// A Bloom filter tells you if an element is definitely not in a set or possibly in a set. It never gives a "false negative," but it might give a "false positive."

// How it works: It uses a bit array and multiple hash functions. When you add an item, you hash it several times and set those bits to 1.

// Use Case: Google Chrome uses this to check if a URL is a known malicious site without storing the entire list of millions of dangerous URLs on your computer.

//check if relates to hashing

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <functional>

template<size_t Size>
class BloomFilter {
private:
    std::bitset<Size> bits;
    int num_hashes;

    // Simple way to generate multiple hashes from a single string
    // by using different "seeds"
    size_t get_hash(const std::string& item, int seed) const {
        std::hash<std::string> hasher;
        return hasher(item + std::to_string(seed)) % Size;
    }

public:
    BloomFilter(int k) : num_hashes(k) {}

    void add(const std::string& item) {
        for (int i = 0; i < num_hashes; ++i) {
            bits.set(get_hash(item, i));
        }
    }

    bool contains(const std::string& item) const {
        for (int i = 0; i < num_hashes; ++i) {
            if (!bits.test(get_hash(item, i))) {
                return false; // Definitely not present
            }
        }
        return true; // Possibly present
    }
};

int main() {
    // A filter with 1024 bits and 3 hash functions
    BloomFilter<1024> filter(3);

    filter.add("gemini");
    filter.add("cpp_data_structures");

    std::cout << std::boolalpha;
    std::cout << "Contains 'gemini': " << filter.contains("gemini") << std::endl;      // true
    std::cout << "Contains 'bloom': " << filter.contains("bloom") << std::endl;        // false (likely)
    
    return 0;
}

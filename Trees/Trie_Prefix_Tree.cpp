#include <iostream>
#include <vector>

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie
    void insert(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    // Returns true if the word is in the trie
    bool search(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    // Returns true if there is any word in the trie that starts with the given prefix
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr = curr->children[index];
        }
        return true;
    }
};

int main() {
    Trie* myTrie = new Trie();

    // 1. Insert words
    std::vector<std::string> words = {"apple", "apply", "bat", "ball"};
    for (const std::string& w : words) {
        myTrie->insert(w);
        std::cout << "Inserted: " << w << std::endl;
    }

    std::cout << "\n--- Search Results ---\n";

    // 2. Full word search
    std::cout << "Search 'apple': " << (myTrie->search("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'app': " << (myTrie->search("app") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'bat': " << (myTrie->search("bat") ? "Found" : "Not Found") << std::endl;

    std::cout << "\n--- Prefix Results ---\n";

    // 3. Prefix search
    std::cout << "Starts with 'app': " << (myTrie->startsWith("app") ? "Yes" : "No") << std::endl;
    std::cout << "Starts with 'ba': " << (myTrie->startsWith("ba") ? "Yes" : "No") << std::endl;
    std::cout << "Starts with 'cat': " << (myTrie->startsWith("cat") ? "Yes" : "No") << std::endl;

    delete myTrie;
    return 0;
}
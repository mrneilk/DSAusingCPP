#include <iostream>
#include <vector>
#include <string>

// Function to build the LPS (Longest Proper Prefix which is also Suffix) array
std::vector<int> buildLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Fall back to the previous longest prefix suffix
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to perform the KMP string matching
void KMPSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return;

    std::vector<int> lps = buildLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            std::cout << "Pattern found at index " << (i - j) << "\n";
            j = lps[j - 1]; // Look for next match
        }
        // Mismatch after j matches
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Do not match lps[0...j-1] characters, they will match anyway
            } else {
                i++;
            }
        }
    }
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABAB";
    
    std::cout << "Text:    " << text << "\n";
    std::cout << "Pattern: " << pattern << "\n\n";
    
    KMPSearch(text, pattern);
    
    return 0;
}

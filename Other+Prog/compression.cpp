#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint> // For int8_t - explaination: This header is included to use the int8_t type, which is a fixed-width integer type that is exactly 8 bits wide. 
//It is part of the C++ standard library and is defined in the <cstdint> header. 
// Using int8_t allows us to represent values in the range of -128 to 127, which is suitable for our quantization process where we want to compress floating-point values into a smaller integer format.

// Simple 8-bit Symmetric Quantizer
class Quantizer {
public:
    float scale;

    // Compresses float array to int8
    std::vector<int8_t> compress(const std::vector<float>& data) {
        float max_abs = 0.0f;
        for (float val : data) max_abs = std::max(max_abs, std::abs(val));
        
        // Calculate the step size (Scale)
        scale = max_abs / 127.0f;
        
        std::vector<int8_t> quantized(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            // Mapping and clipping to ensure we stay in int8 range
            quantized[i] = static_cast<int8_t>(std::round(data[i] / scale));
        }
        return quantized;
    }

    // Reconstructs the data (Lossy)
    std::vector<float> decompress(const std::vector<int8_t>& quantized) {
        std::vector<float> decompressed(quantized.size());
        for (size_t i = 0; i < quantized.size(); ++i) {
            decompressed[i] = quantized[i] * scale;
        }
        return decompressed;
    }
};

int main() {
    std::vector<float> weights = {0.12, -0.98, 0.45, 1.22, -1.10};
    Quantizer q;

    auto compressed = q.compress(weights);
    auto restored = q.decompress(compressed);

    std::cout << "Original: 1.22 -> Compressed: " << (int)compressed[3] << " -> Restored: " << restored[3] << std::endl;
    return 0;
}

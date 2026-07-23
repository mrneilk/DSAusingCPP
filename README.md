# 🚀 DSA Odyssey: Core Architectures in C++

A personalized laboratory for Data Structures and Algorithms, focusing on low-level memory management, efficient system design, and high-performance computing logic.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Logic-Data_Structures-orange?style=for-the-badge)

---

## 🏗️ System Overview

This repository transitions from fundamental linear structures to complex probabilistic models and graph theory, with a specific focus on how these structures manifest in system memory.

### 🔢 Arrays & Linear Storage
* **Contiguous Logic:** Implementation of static arrays vs. `std::vector` overhead.
* **Complexity:** Optimized for $O(1)$ random access.
* **Mechanics:** Exploring cache locality and how contiguous memory affects CPU performance.

### 🕸️ Graph Theory & Network Topologies
* **Adjacency Models:** Sparse graph optimization using `std::vector<int> adj[]` vs. dense graph Adjacency Matrices.
* **Traversal Engines:** * **BFS:** Level-order discovery for shortest paths in unweighted networks.
    * **DFS:** Deep-dive recursion for topological sorting and cycle detection.

### 💾 In-Memory View (The Memory Model)
A deep look into the "Where" and "How" of data storage:
* **Stack vs. Heap:** Analyzing local scope lifecycle vs. dynamic allocation via `new`/`delete`.
* **Pointer Arithmetic:** Managing references to prevent memory leaks and fragmentation.
* **Buffer Management:** How structures are laid out in the process address space.

### 🌫️ Probabilistic Structures: Bloom Filters
* **Space Efficiency:** Using bitsets and hashing to handle set-membership tests with zero false negatives.
* **Hashing Logic:** Implementing multiple hash functions to tune the false-positive rate.
* **Use Cases:** System-level cache filtering and database query optimization.



---

## 🛠️ Repository Roadmap

| Module | Implementation Status | Key Concepts |
| :--- | :---: | :--- |
| **Arrays** | ✅ Complete | Sliding Window, Two-Pointer, Kadane’s |
| **Graphs** | ✅ Complete | Dijkstra, Prim's, BFS/DFS Traversal |
| **Trees** | ✅ Complete | BST, AVL, Red-Black Tree, Heaps |
| **In-Memory** | ✅ Complete | RAII, Smart Pointers, Stack Frames |
| **Bloom Filters**| ✅ Complete | MurmurHash, Bitsets, Error-Rates |
| **List**| ✅ Complete  | Linked List, Circular |
| **Sorting and Searching**| In Progress  | Search and Sort Algorithms |
| **Stacks and Queue**| In Progress  | Stack and Queues and variations |

---

## 🚀 Getting Started

### Prerequisites
* A C++17 compatible compiler (GCC/Clang/MSVC)
* Make or CMake (Optional for automated builds)
* VSCode
* Git

### Build & Execute
```bash
# Clone the repository
git clone [https://github.com/mrneilk/DSAusingCPP.git](https://github.com/mrneilk/DSAusingCPP.git)

# Navigate to a specific module
cd Graphs

# Compile using G++
g++ -std=c++17 main.cpp -o graph_engine

# Run the binary
./graph_engine

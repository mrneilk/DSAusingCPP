# DSA using CPP
DSA problems using C++ language

## Arrays
An array is a linear data structure that stores elements of the same type in contiguous memory locations. In C++, you can use static arrays int arr[5] or dynamic arrays via std::vector, which manage resizing automatically. They offer $O(1)$ time complexity for accessing elements by index.

## Graphs
Graphs consist of nodes (vertices) connected by edges, representing complex relationships like social networks or map routes. In C++, they are typically implemented using an Adjacency List (vector<int> adj[]) for space efficiency or an Adjacency Matrix for quick edge lookups. Common traversal algorithms include BFS (Breadth-First Search) and DFS (Depth-First Search).

## In Memory View
When a C++ program runs, memory is divided into the Stack (for local variables and function calls) and the Heap (for dynamic memory allocated via new). Understanding this "view" is crucial for DSA to prevent memory leaks and manage pointers effectively. Arrays are typically stored in a single block, while graph nodes in an adjacency list may be scattered across the heap.

## Bloom Filters

## Other Programs

## Trees

This need more update

# 🚀 DSA Odyssey: Core Architectures in C++

A specialized laboratory for Data Structures and Algorithms, focusing on low-level memory management, efficient system design, and high-performance computing logic.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Logic-Data_Structures-orange?style=for-the-badge)
![Linux](https://img.shields.io/badge/OS-Linux-f0b041?style=for-the-badge&logo=linux&logoColor=black)

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
| **Graphs** | 🏗️ In Progress | Dijkstra, Prim's, BFS/DFS Traversal |
| **Trees** | 📝 Planned | BST, AVL, Red-Black Tree, Heaps |
| **In-Memory** | ✅ Complete | RAII, Smart Pointers, Stack Frames |
| **Bloom Filters**| 🧪 Experimental | MurmurHash, Bitsets, Error-Rates |

---

## 🚀 Getting Started

### Prerequisites
* A C++17 compatible compiler (GCC/Clang/MSVC)
* Make or CMake (Optional for automated builds)

### Build & Execute
```bash
# Clone the repository
git clone [https://github.com/YourUsername/DSA-using-CPP.git](https://github.com/YourUsername/DSA-using-CPP.git)

# Navigate to a specific module
cd Graphs

# Compile using G++
g++ -std=c++17 main.cpp -o graph_engine

# Run the binary
./graph_engine

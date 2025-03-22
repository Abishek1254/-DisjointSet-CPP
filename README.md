# Disjoint Set Data Structure (Union-Find) in C++

A **C++ implementation** of the **Disjoint Set Data Structure** (also known as **Union-Find**) with **path compression** and **union by rank/size**. This data structure is widely used in algorithms involving connected components, such as Kruskal’s algorithm for Minimum Spanning Trees (MST), network connectivity, and more.

---

## Features

- **Find**: Find the root of a set with **path compression** for optimal performance.
- **Union**: Merge two sets using either **union by rank** or **union by size** to keep the tree balanced.
- **isConnected**: Check if two elements belong to the same set.
- **Easy to Use**: Simply include the `DisjointSet.h` header file in your project.

---

## How to Use
1. Download the `DisjointSet.h` file.
2. Place it in your project’s include directory or system-wide include path (e.g., `/usr/local/include` on Linux/macOS).
3. Include it in your code:
   ```cpp
   #include <DisjointSet.h>

Alternatively, you can clone the entire repository:
```bash
git clone https://github.com/Abishek1254/-DisjointSet-CPP.git

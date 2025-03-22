# Disjoint Set Data Structure (Union-Find) in C++

A C++ implementation of the Disjoint Set Data Structure with **path compression** and **union by rank/size**.

## Features
- **Find**: Find the root(ultimate parent) of a set.
- **Union**: Merge two sets using either rank or size.
- **isConnected**: Check if two elements are in the same set.

## Usage

1. Include the `DisjointSet.h` header file in your project.
2. Create a `DisjointSet` object with the number of elements.
3. Use the `unionByRank`, `unionBySize`, and `findUpar` methods to manage sets.

### Example
See the `main.cpp` file for an example usage:

```cpp
#include "DisjointSet.h"

int main() {
    DisjointSet ds(5);
    ds.unionBySize(1, 2);
    ds.unionBySize(3, 4);

    if (ds.isConnected(1, 2)) {
        cout << "1 and 2 are connected!" << endl;
    }

    return 0;
}

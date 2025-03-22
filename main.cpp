#include <iostream>
#include "DisjointSet.h"
using namespace std;

int main() {
    // Create a DisjointSet object with 7 elements (0 to 7)
    DisjointSet ds(7);

    // Perform union operations using unionBySize
    ds.unionBySize(1, 2);
    ds.unionBySize(4, 5);

    // Check if 2 and 3 are in the same set
    if (ds.isConnected(2, 3)) 
      cout << "Before: 2 and 3 belong to the same set" << endl;
    else 
      cout << "Before: 2 and 3 do not belong to the same set" << endl;
    
    // Perform union operation on 2 and 3
    ds.unionBySize(2, 3);

    // Check if 2 and 3 are in the same set after union
    if (ds.isConnected(2, 3)) 
        cout << "After: 2 and 3 belong to the same set" << endl;
    else 
      cout << "After: 2 and 3 do not belong to the same set" << endl;

    
    return 0;
}

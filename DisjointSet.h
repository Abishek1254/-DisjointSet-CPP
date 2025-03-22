#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>
#include <stdexcept>
using namespace std;

class DisjointSet {
private:
    // Vectors to store parent, rank, and size of each set
    vector<int> parent; // Stores the parent of each element
    vector<int> rank;   // Stores the rank (depth) of each set
    vector<int> size;   // Stores the size of each set

public:
    // Constructor to initialize the Disjoint Set Data Structure
    DisjointSet(int n) {
        // Resize vectors to handle both 0-based and 1-based indexing
        rank.resize(n + 1, 0);  // Initialize rank of all sets to 0
        parent.resize(n + 1);   // Resize parent vector
        size.resize(n + 1, 1);  // Initialize size of all sets to 1

        // Initialize each element as its own parent
        for (int i = 0; i <= n; i++) 
         parent[i] = i;
        
    }

    // Find the ultimate parent of a node with path compression
    int findUpar(int u) {
        if (parent[u] == u) 
         return u; // If u is its own parent, return u
        
        // Path compression: Update the parent of u to its ultimate parent
        return parent[u] = findUpar(parent[u]);
    }

    // Union two sets using the rank-based method
    void unionByRank(int u, int v) {
        int ulp_u = findUpar(u); // Ultimate parent of u
        int ulp_v = findUpar(v); // Ultimate parent of v

        if (ulp_u == ulp_v) 
         return; // If both elements are already in the same set, do nothing
        

        // Attach the smaller rank tree under the root of the larger rank tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } 
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
         else {
            // If ranks are equal, attach one to the other and increase the rank
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    // Union two sets using the size-based method
    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u); // Ultimate parent of u
        int ulp_v = findUpar(v); // Ultimate parent of v

        if (ulp_u == ulp_v) 
            return; // If both elements are already in the same set, do nothing
        
        // Attach the smaller size tree under the root of the larger size tree
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; // Update the size of the new set
        } 
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; // Update the size of the new set
        }
    }

    // Check if two elements are in the same set
    bool isConnected(int x, int y) {
        return findUpar(x) == findUpar(y); // Compare ultimate parents
    }

};

#endif // DISJOINTSET_H

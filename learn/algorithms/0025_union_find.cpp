/**
 * Union-Find (DSU)
 * 
 * Efficiently manages disjoint sets with Union and Find operations. 
 * Includes path compression and union by rank.
 */
#include <iostream>
#include <vector>
#include <numeric>

class DSU {
    std::vector<int> parent;
    std::vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) std::swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j]) rank[root_i]++;
        }
    }
};

int main() {
    DSU dsu(5);
    dsu.unite(0, 2); dsu.unite(4, 2); dsu.unite(3, 1);
    std::cout << "0 and 4 connected? " << (dsu.find(0) == dsu.find(4)) << std::endl;
    std::cout << "0 and 3 connected? " << (dsu.find(0) == dsu.find(3)) << std::endl;
    return 0;
}

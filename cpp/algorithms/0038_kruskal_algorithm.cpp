/**
 * Kruskal's Algorithm (MST)
 * 
 * Finds the Minimum Spanning Tree of a connected, weighted graph 
 * using Union-Find. O(E*logE).
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

int kruskal(int V, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mst_weight = 0;
    for (auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_weight += edge.weight;
            std::cout << "Edge " << edge.u << "-" << edge.v << " (w:" << edge.weight << ") added to MST" << std::endl;
        }
    }
    return mst_weight;
}

int main() {
    int V = 4;
    std::vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    std::cout << "MST Total Weight: " << kruskal(V, edges) << std::endl;
    return 0;
}

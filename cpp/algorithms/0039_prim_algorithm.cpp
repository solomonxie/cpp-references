/**
 * Prim's Algorithm (MST)
 * 
 * Finds the Minimum Spanning Tree of a connected, weighted graph 
 * using a priority queue. O(E*logV).
 */
#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii;

int prim(int V, std::vector<std::vector<pii>>& adj) {
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    std::vector<bool> inMST(V, false);
    int mst_weight = 0;

    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mst_weight += w;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v]) pq.push({weight, v});
        }
    }
    return mst_weight;
}

int main() {
    int V = 4;
    std::vector<std::vector<pii>> adj(V);
    adj[0].push_back({1, 10}); adj[1].push_back({0, 10});
    adj[0].push_back({2, 6}); adj[2].push_back({0, 6});
    adj[0].push_back({3, 5}); adj[3].push_back({0, 5});
    adj[1].push_back({3, 15}); adj[3].push_back({1, 15});
    adj[2].push_back({3, 4}); adj[3].push_back({2, 4});

    std::cout << "MST Total Weight: " << prim(V, adj) << std::endl;
    return 0;
}

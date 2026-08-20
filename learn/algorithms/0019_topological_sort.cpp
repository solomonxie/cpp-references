/**
 * Topological Sort (Kahn's Algorithm)
 * 
 * Linear ordering of vertices in a Directed Acyclic Graph (DAG) such 
 * that for every directed edge $uv$, vertex $u$ comes before $v$.
 */
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> topologicalSort(int V, std::vector<std::vector<int>>& adj) {
    std::vector<int> in_degree(V, 0);
    for (int i = 0; i < V; i++)
        for (auto it : adj[i]) in_degree[it]++;

    std::queue<int> q;
    for (int i = 0; i < V; i++) if (in_degree[i] == 0) q.push(i);

    std::vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto v : adj[u]) {
            if (--in_degree[v] == 0) q.push(v);
        }
    }
    return topo;
}

int main() {
    int V = 6;
    std::vector<std::vector<int>> adj(V);
    adj[5].push_back(2); adj[5].push_back(0); adj[4].push_back(0); 
    adj[4].push_back(1); adj[2].push_back(3); adj[3].push_back(1);

    std::vector<int> res = topologicalSort(V, adj);
    std::cout << "Topological Sort: ";
    for (int x : res) std::cout << x << " ";
    return 0;
}

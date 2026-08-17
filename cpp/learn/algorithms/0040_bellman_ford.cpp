/**
 * Bellman-Ford Algorithm
 * 
 * Finds shortest paths from a source to all other vertices in a graph 
 * that may contain negative edge weights. O(V*E).
 */
#include <iostream>
#include <vector>

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int src, std::vector<Edge>& edges) {
    std::vector<int> dist(V, 1e9);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (auto& edge : edges) {
            if (dist[edge.u] != 1e9 && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (auto& edge : edges) {
        if (dist[edge.u] != 1e9 && dist[edge.u] + edge.weight < dist[edge.v]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    for (int i = 0; i < V; ++i) std::cout << "Node " << i << ": " << dist[i] << std::endl;
}

int main() {
    int V = 5;
    std::vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    bellmanFord(V, 0, edges);
    return 0;
}

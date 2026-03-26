/**
 * BFS & DFS (Graph)
 * 
 * Breadth-First Search (queue) and Depth-First Search (recursion/stack) 
 * for graph traversal.
 */
#include <iostream>
#include <vector>
#include <queue>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;
public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int v, int w) { adj[v].push_back(w); }

    void BFS(int s) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;
        visited[s] = true; q.push(s);
        while (!q.empty()) {
            s = q.front(); q.pop();
            std::cout << s << " ";
            for (auto i : adj[s]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true; std::cout << v << " ";
        for (auto i : adj[v]) if (!visited[i]) DFSUtil(i, visited);
    }
    void DFS(int v) {
        std::vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 2); g.addEdge(2, 0); g.addEdge(2, 3); g.addEdge(3, 3);
    std::cout << "BFS starting from vertex 2: "; g.BFS(2);
    std::cout << "\nDFS starting from vertex 2: "; g.DFS(2);
    return 0;
}

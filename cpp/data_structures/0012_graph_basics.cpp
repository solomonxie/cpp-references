// Lesson: Graph Basics - Adjacency List representation
// Compile: g++ -o 0012_graph_basics 0012_graph_basics.cpp

#include <iostream>
#include <list>
#include <vector>

class Graph {
  int numVertices;
  std::vector<std::list<int>> adjLists;

public:
  Graph(int vertices) : numVertices(vertices) { adjLists.resize(vertices); }

  // Add undirected edge
  void addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
  }

  void printGraph() {
    for (int i = 0; i < numVertices; i++) {
      std::cout << "Vertex " << i << ":";
      for (int neighbor : adjLists[i]) {
        std::cout << " -> " << neighbor;
      }
      std::cout << "\n";
    }
  }
};

int main() {
  Graph g(4);

  std::cout << "Adding edges...\n";
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  std::cout << "Adjacency List representation:\n";
  g.printGraph();

  return 0;
}

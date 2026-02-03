# C++ Data Structures Lessons

This folder contains educational code pieces for common data structures in C++.
Each file is a standalone lesson that can be compiled and executed independently.

## Curriculum

| Order | Filename | Topic | Key Concepts |
|---|---|---|---|
| 01 | `0001_array.cpp` | Static Array | `std::array`, C-style array, indexing |
| 02 | `0002_vector.cpp` | Dynamic Array | `std::vector`, resizing, capacity |
| 03 | `0003_singly_linked_list.cpp` | Singly Linked List | Nodes, next pointer, manual memory |
| 04 | `0004_doubly_linked_list.cpp` | Doubly Linked List | Previous pointer, bi-directional traversal |
| 05 | `0005_stack.cpp` | Stack | LIFO, `push`, `pop`, `top` |
| 06 | `0006_queue.cpp` | Queue | FIFO, `push`, `pop`, `front` |
| 07 | `0007_deque.cpp` | Deque | Double-ended, front/back operations |
| 08 | `0008_hash_table.cpp` | Hash Table | `std::unordered_map`, key-value lookup |
| 09 | `0009_binary_tree.cpp` | Binary Tree | Hierarchy, In-order, Pre-order traversal |
| 10 | `0010_binary_search_tree.cpp` | Binary Search Tree | Ordered tree, search, insert |
| 11 | `0011_heap.cpp` | Heap | `std::priority_queue`, Max-heap, Min-heap |
| 12 | `0012_graph_basics.cpp` | Graph | Adjacency list, vertices, edges |

## How to use

Each file contains a compilation command in its header. For example:
```bash
g++ -o 0001_array 0001_array.cpp
./0001_array
```

Most lessons use the C++ Standard Library (STL). Some demonstrate manual pointer-based implementations for educational purposes.

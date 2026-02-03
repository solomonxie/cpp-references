// Lesson: Doubly Linked List - Nodes with next and previous pointers
// Compile: g++ -o 0004_doubly_linked_list 0004_doubly_linked_list.cpp

#include <iostream>

struct Node {
  int data;
  Node *next;
  Node *prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  // Insert at the end
  void append(int val) {
    Node *newNode = new Node(val);
    if (!head) {
      head = tail = newNode;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  // Print forward
  void displayForward() {
    Node *temp = head;
    while (temp) {
      std::cout << temp->data << " <-> ";
      temp = temp->next;
    }
    std::cout << "nullptr\n";
  }

  // Print backward
  void displayBackward() {
    Node *temp = tail;
    while (temp) {
      std::cout << temp->data << " <-> ";
      temp = temp->prev;
    }
    std::cout << "nullptr\n";
  }

  // Clean up
  ~DoublyLinkedList() {
    Node *current = head;
    while (current) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }
};

int main() {
  DoublyLinkedList dll;
  std::cout << "Appending 1, 2, 3...\n";
  dll.append(1);
  dll.append(2);
  dll.append(3);

  std::cout << "Forward: ";
  dll.displayForward();

  std::cout << "Backward: ";
  dll.displayBackward();

  return 0;
}

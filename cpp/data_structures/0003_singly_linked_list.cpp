// Lesson: Singly Linked List - Chain of nodes containing data and next pointer
// Compile: g++ -o 0003_singly_linked_list 0003_singly_linked_list.cpp

#include <iostream>

// Node structure
struct Node {
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  // Insert at the beginning
  void insertAtHead(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  // Print the list
  void display() {
    Node *temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }
    std::cout << "nullptr\n";
  }

  // Delete a node with specific value
  void remove(int val) {
    if (!head)
      return;

    if (head->data == val) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *current = head;
    while (current->next && current->next->data != val) {
      current = current->next;
    }

    if (current->next) {
      Node *temp = current->next;
      current->next = current->next->next;
      delete temp;
    }
  }

  // Destructor to clean up memory
  ~LinkedList() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  LinkedList list;

  std::cout << "Inserting 10, 20, 30 at head...\n";
  list.insertAtHead(10);
  list.insertAtHead(20);
  list.insertAtHead(30);

  std::cout << "List contents: ";
  list.display();

  std::cout << "Removing 20...\n";
  list.remove(20);

  std::cout << "List contents: ";
  list.display();

  return 0;
}

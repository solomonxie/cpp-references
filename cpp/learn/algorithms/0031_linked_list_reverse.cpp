/**
 * Linked List - Reverse
 * 
 * Demonstrates iterative and recursive methods to reverse a singly 
 * linked list.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Iterative Reversal
ListNode* reverseIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive Reversal
ListNode* reverseRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* p = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    std::cout << "Original: "; printList(head);
    head = reverseIterative(head);
    std::cout << "Reversed (Iterative): "; printList(head);
    head = reverseRecursive(head);
    std::cout << "Reversed (Recursive): "; printList(head);

    return 0;
}

/**
 * Linked List - Cycle Detection
 * 
 * Floyd's Tortoise and Hare algorithm to detect a cycle in O(n) time 
 * and O(1) space.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next; // Create cycle: 3 -> 2

    std::cout << "Has Cycle? " << (hasCycle(head) ? "Yes" : "No") << std::endl;
    return 0;
}

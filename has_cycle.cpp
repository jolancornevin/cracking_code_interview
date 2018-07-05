// ctci-linked-list-cycle

#include <map>
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    std::map<Node*, bool> mapEncountered;
    // Loop until we are at the end of the list of we find a cycle.
    while (head && head->next) {
        // We've already seen this @, we return true;
        if (mapEncountered[head] == true)
            return true;
        // Mark the element as seen.
        mapEncountered[head] = true;
        // Move forward in the list.
        head = head->next;
    }
    // We've arrived at the end of list, there is no cycle inside.
    return false;
}

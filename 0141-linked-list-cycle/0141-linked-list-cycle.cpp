/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        
        // Traverse the list
        ListNode* current = head;
        while (current != NULL) {
            // If the current node is already in the set, a cycle is detected
            if (visited.find(current) != visited.end()) {
                return true;
            }
            // Otherwise, add the current node to the set
            visited.insert(current);
            // Move to the next node
            current = current->next;
        }
        
        // If we reach here, there's no cycle
        return false;
        
    }
};
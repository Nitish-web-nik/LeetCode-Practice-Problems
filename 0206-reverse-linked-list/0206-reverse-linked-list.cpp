class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextTemp = curr->next; // Store next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr; // Move prev forward
            curr = nextTemp; // Move curr forward
        }

        return prev;
    }
};

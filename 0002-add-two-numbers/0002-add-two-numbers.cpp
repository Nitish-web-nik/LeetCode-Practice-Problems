/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current1 = l1;
        ListNode* prev = nullptr;  // To keep track of the last node of l1
        int carry = 0;

        // Traverse both linked lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
            }
            
            carry = sum / 10;

            if (l1 != nullptr) {
                l1->val = sum % 10;  // Modify l1 node in place
                prev = l1;  // Keep track of last modified node
                l1 = l1->next;
            } else {
                // If l1 is exhausted, append nodes from l2
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return current1;
    }
};

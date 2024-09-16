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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        while(headB != NULL) {
        ListNode* temp = headA;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == headB) return headB;
            temp = temp->next;
        }
        headB = headB->next;
    }
    //intersection is not present between the lists return null
    return NULL;
    }
};
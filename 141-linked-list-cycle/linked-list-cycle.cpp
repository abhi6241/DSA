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
        ListNode* slow = head;
        ListNode* fast = head;

        // Check whether the 2 pointers meet or not
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            // Return true of they meet or false if they don't
            if(fast == slow) return true;
        }

        return false;
    }
};
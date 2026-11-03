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
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Check whether a cycle exists
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        // No cycle exists
        if(fast == NULL || fast->next == NULL)
            return NULL;

        // Find the starting node of the cycle
        slow = head;

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
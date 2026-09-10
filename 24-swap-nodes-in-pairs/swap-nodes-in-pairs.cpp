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
    ListNode* swapPairs(ListNode* head) {
        // Dummy node makes it easier to handle the first pair
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while(prev->next && prev->next->next) {

            // Store the two nodes we want to swap
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        return dummy->next;
    }
};
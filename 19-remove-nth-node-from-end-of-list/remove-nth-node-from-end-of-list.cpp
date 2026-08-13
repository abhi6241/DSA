class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        // Move temp n nodes ahead.
        for (int i = 0; i < n; i++)
            temp = temp->next;

        // If temp is NULL, remove the first node.
        if (temp == NULL)
            return head->next;

        ListNode* prev = head;

        // Move until temp reaches the last node.
        while (temp->next != NULL) {
            temp = temp->next;
            prev = prev->next;
        }

        // Remove the nth node from the end.
        prev->next = prev->next->next;

        return head;
    }
};
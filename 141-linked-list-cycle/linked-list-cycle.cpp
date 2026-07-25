class Solution {
public:
    bool hasCycle(ListNode *head) {
        // No cycle possible if list has 0 or 1 node
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) return true;
        }

        return false;
    }
};

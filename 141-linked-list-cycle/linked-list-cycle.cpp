class Solution {
public:
    bool hasCycle(ListNode *head) {
        // No cycle possible if list has 0 or 1 node
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Advance pointers directly and verify structural limits inside the condition
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

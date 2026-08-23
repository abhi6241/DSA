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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<TreeNode*>& nodes, int i, int j) {
        if (i > j)
            return nullptr;

        int mid = i + (j - i) / 2;

        nodes[mid]->left = helper(nodes, i, mid - 1);
        nodes[mid]->right = helper(nodes, mid + 1, j);

        return nodes[mid];
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<TreeNode*> nodes;

        while (head) {
            nodes.push_back(new TreeNode(head->val));
            head = head->next;
        }

        return helper(nodes, 0, nodes.size() - 1);
    }
};
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
    TreeNode* build(
        vector<int>& inorder,
        int inStart,
        int inEnd,
        vector<int>& postorder,
        int pStart,
        int pEnd,
        map<int, int>& m
    ) {
        // No elements left to construct the subtree.
        if (pStart > pEnd || inStart > inEnd)
            return NULL;

        // Last element of postorder is the root.
        TreeNode* root = new TreeNode(postorder[pEnd]);

        // Find the root's position in inorder.
        int inRoot = m[root->val];

        // Number of nodes in the left subtree.
        int numsLeft = inRoot - inStart;

        // Build the left subtree.
        root->left = build(
            inorder,
            inStart,
            inRoot - 1,
            postorder,
            pStart,
            pStart + numsLeft - 1,
            m
        );

        // Build the right subtree.
        root->right = build(
            inorder,
            inRoot + 1,
            inEnd,
            postorder,
            pStart + numsLeft,
            pEnd - 1,
            m
        );

        return root;
    }

    TreeNode* buildTree(
        vector<int>& inorder,
        vector<int>& postorder
    ) {
        // Invalid input if sizes are different.
        if (inorder.size() != postorder.size())
            return NULL;

        map<int, int> m;

        // Store each value's index in inorder.
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        return build(
            inorder,
            0,
            inorder.size() - 1,
            postorder,
            0,
            postorder.size() - 1,
            m
        );
    }
};
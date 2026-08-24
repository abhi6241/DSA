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
private:
    unordered_map<int, int> inorderIndex;

    TreeNode* build(
        vector<int>& preorder,
        int preStart,
        int preEnd,
        int inStart,
        int inEnd
    ) {
        // No elements left to build.
        if (preStart > preEnd)
            return nullptr;

        // First element of preorder is the root.
        int rootValue = preorder[preStart];

        // Find the root's position in inorder.
        int mid = inorderIndex[rootValue];

        // Number of nodes in the left subtree.
        int leftSize = mid - inStart;

        TreeNode* root = new TreeNode(rootValue);

        // Build the left subtree.
        root->left = build(
            preorder,
            preStart + 1,
            preStart + leftSize,
            inStart,
            mid - 1
        );

        // Build the right subtree.
        root->right = build(
            preorder,
            preStart + leftSize + 1,
            preEnd,
            mid + 1,
            inEnd
        );

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store each value's index in inorder for O(1) lookup.
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(
            preorder,
            0,
            preorder.size() - 1,
            0,
            inorder.size() - 1
        );
    }
};
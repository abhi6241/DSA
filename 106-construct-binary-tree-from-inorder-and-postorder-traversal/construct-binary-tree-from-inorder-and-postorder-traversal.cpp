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

    TreeNode* build(vector<int>& inorder, vector<int>postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd)
            return nullptr;

        // Last element of postorder is the root.
        int rootValue = postorder[postEnd];
        int mid = inorderIndex[rootValue];

        // Number of nodes in the left subtree.
        int leftSize = mid - inStart;

        TreeNode* root = new TreeNode(rootValue);

        // Build left subtree.
        root->left = build(inorder, postorder, inStart, mid - 1, postStart, postStart + leftSize - 1);

        // Build right subtree.
        root->right = build(inorder, postorder, mid + 1, inEnd, postStart + leftSize, postEnd - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Store each value's index in inorder for O(1) lookup.
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1
        );
    }
};
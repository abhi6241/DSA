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
    TreeNode* build(vector<int>& preorder, vector<int>& postorder,
                    int preStart, int preEnd,
                    int postStart, int postEnd) {

        if (preStart > preEnd)
            return nullptr;

        // First element of preorder is the root.
        TreeNode* root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd)
            return root;

        // The next preorder element is the left subtree's root.
        int leftRoot = preorder[preStart + 1];

        // Find that node in postorder.
        int i = postStart;
        while (postorder[i] != leftRoot)
            i++;

        // Number of nodes in the left subtree.
        int leftSize = i - postStart + 1;

        // Build left subtree.
        root->left = build(
            preorder, postorder,
            preStart + 1,
            preStart + leftSize,
            postStart,
            i
        );

        // Build right subtree.
        root->right = build(
            preorder, postorder,
            preStart + leftSize + 1,
            preEnd,
            i + 1,
            postEnd - 1
        );

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        return build(
            preorder, postorder,
            0, preorder.size() - 1,
            0, postorder.size() - 1
        );
    }
};
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
    int preIndex = 0;
    int postIndex = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        // Take the next node from preorder as root.
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // If root is not the current postorder node,
        // there is a left subtree to build.
        if (root->val != postorder[postIndex]) {
            root->left = constructFromPrePost(preorder, postorder);
        }

        // If root is still not the current postorder node,
        // there is a right subtree to build.
        if (root->val != postorder[postIndex]) {
            root->right = constructFromPrePost(preorder, postorder);
        }

        // Current root is now reached in postorder.
        postIndex++;

        return root;
    }
};
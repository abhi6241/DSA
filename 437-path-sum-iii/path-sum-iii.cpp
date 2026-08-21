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
    unordered_map<long long, int> mp;
    
    int solve(TreeNode* root, long long curr, int targetSum) {
        if (!root)
            return 0;

        curr += root->val;

        int count = 0;

        // Check if a previous prefix sum gives the target path.
        if (mp.count(curr - targetSum))
            count += mp[curr - targetSum];

        mp[curr]++;

        count += solve(root->left, curr, targetSum);
        count += solve(root->right, curr, targetSum);

        // Backtrack: remove this prefix sum before returning.
        mp[curr]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return solve(root, 0, targetSum);
    }
};
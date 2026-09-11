class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int i) {

        // Target reached, so we found a valid combination
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        // No more candidates or target became negative
        if(i == candidates.size() || target < 0)
            return;

        // Choose the current number
        temp.push_back(candidates[i]);

        // Use the same number again
        solve(candidates, target - candidates[i], i);

        // Remove the number before trying another choice
        temp.pop_back();

        // Skip the current number and try the next one
        solve(candidates, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};
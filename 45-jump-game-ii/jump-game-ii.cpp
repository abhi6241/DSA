class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int end = 0;
        int maxReach = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            // Farthest position reachable from current range
            maxReach = max(maxReach, i + nums[i]);

            // Reached the end of the current jump
            if(i == end) {
                count++;
                end = maxReach;
            }
        }

        return count;
    }
};
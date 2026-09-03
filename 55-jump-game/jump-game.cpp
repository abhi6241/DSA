class Solution {
public:
    bool canJump(vector<int>& nums) {
       int size = nums.size() ;
       int maxReach = 0;

       for(int i = 0; i < size; i++) {
            // If current index is beyond what we can reach,
            // then we are stuck.
            if(i > maxReach) return false;

            // Update the farthest index we can reach
            maxReach = max(maxReach, i + nums[i]);

            // We can already reach the last index
            if(maxReach >= size - 1) return true;
        }

        return true;
    }
};
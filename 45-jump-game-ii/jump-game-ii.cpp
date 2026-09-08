class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int maxReach = 0;
        int end = 0;
        int count = 0;

        // We don't need to jump if there is only one element
        if(size == 1)
            return 0;

        for(int i = 0; i < size - 1; i++) {

            // Find the farthest position reachable
            // from the current range
            maxReach = max(maxReach, i + nums[i]);

            // We have reached the end of the current jump range
            if(i == end) {
                count++;

                // Start a new range
                end = maxReach;

                // We can already reach the last index
                if(end >= size - 1)
                    break;
            }
        }

        return count;
    }
};
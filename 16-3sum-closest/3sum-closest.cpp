class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size() - 2; i++) {

            // Skip duplicate values
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // Update closest sum if this one is nearer to target
                if(abs(target - sum) < abs(target - closest))
                    closest = sum;

                // If sum is smaller, increase it
                if(sum < target)
                    left++;

                // If sum is larger, decrease it
                else if(sum > target)
                    right--;

                // Exact target found
                else
                    return sum;
            }
        }

        return closest;
    }
};
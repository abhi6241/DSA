class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sort the array so we can use two pointers
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {

            // Skip duplicate values for the first number
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            // Find two numbers whose sum is -nums[i]
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate second numbers
                    while(left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicate third numbers
                    while(left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if(sum < 0) {
                    // Need a larger sum
                    left++;
                }
                else {
                    // Need a smaller sum
                    right--;
                }
            }
        }

        return ans;
    }
};
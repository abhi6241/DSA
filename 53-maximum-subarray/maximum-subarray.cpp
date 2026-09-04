class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];

        for(int i = 0; i < nums.size(); i++) {

            // Add the current element to the subarray
            sum += nums[i];

            // Update the maximum sum found so far
            maxSum = max(maxSum, sum);

            // If the current sum becomes negative,
            // it is better to start a new subarray.
            if(sum < 0)
                sum = 0;
        }

        return maxSum;
    }
};
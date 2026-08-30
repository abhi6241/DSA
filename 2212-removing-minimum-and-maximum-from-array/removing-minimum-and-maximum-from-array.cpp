class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minVal = nums[0], maxVal = nums[0];
        int minIndex = 0, maxIndex = 0;

        // Find minimum value and its index.
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIndex = i;
            }

            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }

        // Make minIndex the smaller index.
        if (minIndex > maxIndex)
            swap(minIndex, maxIndex);

        // Remove both from the front.
        int case1 = maxIndex + 1;

        // Remove both from the back.
        int case2 = nums.size() - minIndex;

        // Remove min from front and max from back.
        int case3 = minIndex + 1 + nums.size() - maxIndex;

        return min({case1, case2, case3});
    }
};
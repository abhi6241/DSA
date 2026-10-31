class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // As the numbers are 3, divide them by 3
        long long temp = num / 3;

        // Check whether the given number is divisible by 3
        if(num % 3 == 0) {
            return {temp - 1, temp, temp + 1};
        }

        // Return empty array if the given number is not divisible by 3
        return {};
    }
};
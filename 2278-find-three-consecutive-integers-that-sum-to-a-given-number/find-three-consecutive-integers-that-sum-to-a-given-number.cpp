class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long temp = num / 3;

        if(num % 3 == 0) {
            return {temp - 1, temp, temp + 1};
        }

        return {};
    }
};
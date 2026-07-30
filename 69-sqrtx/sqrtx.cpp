class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;

        for (long long i = 0; i <= x; i++) {
            if (i * i <= x)
                ans = i;
            else
                break;   // Stop once i² exceeds x.
        }

        return ans;
    }
};
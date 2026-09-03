class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Use long long to safely handle INT_MIN

        // If exponent is negative, take reciprocal
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        // Binary exponentiation
        while(N > 0) {

            // If the current bit is 1, multiply answer by x
            if(N % 2 == 1) {
                ans *= x;
            }

            // Square x for the next power
            x *= x;

            // Move to the next bit
            N /= 2;
        }

        return ans;
    }
};
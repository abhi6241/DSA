class Solution {
public:
    int divide(int dividend, int divisor) {
        // Only case where the mathematical answer cannot fit inside an int
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Conver to positive long long values
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        // Keep taking chunks until dividend < divisor
        while(a >= b) {
            // Start with one divisor
            long long temp = b;
            long long multiple = 1;

            // Double the divisor as much as possible
            while(a > temp + temp) {
                temp = temp + temp;
                multiple = multiple + multiple;
            }

            // Remove that chunk
            a = a - temp;

            // Add how many divisors were removed
            ans = ans + multiple;
        }

        // Determine the sign
        if((dividend < 0) != (divisor < 0))
            ans = -ans;

        return int(ans);
    }
};
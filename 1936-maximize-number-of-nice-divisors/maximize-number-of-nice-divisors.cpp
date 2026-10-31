class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        // Binary exponentiation
        while(b > 0) {
            if(b % 2 == 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b /= 2;
        }

        return ans;
    }

    int maxNiceDivisors(int primeFactors) {

        if(primeFactors <= 3)
            return primeFactors;

        // Prefer factors of 3 for maximum product
        if(primeFactors % 3 == 0)
            return power(3, primeFactors / 3);

        // If remainder is 1, replace 3 + 1 with 2 + 2
        if(primeFactors % 3 == 1)
            return (power(3, (primeFactors - 4) / 3) * 4) % MOD;

        // If remainder is 2, keep the remaining factor 2
        return (power(3, primeFactors / 3) * 2) % MOD;
    }
};
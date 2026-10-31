
class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:

        MOD = 10**9 + 7

        # If primeFactors is 1, answer is 1
        if primeFactors == 1:
            return 1

        # Use as many 3s as possible
        q, r = divmod(primeFactors, 3)

        # If remainder is 0, use only 3s
        if r == 0:
            return pow(3, q, MOD)

        # If remainder is 1, replace one 3 with 2 + 2
        elif r == 1:
            return (pow(3, q - 1, MOD) * 4) % MOD

        # If remainder is 2, multiply by 2
        else:
            return (pow(3, q, MOD) * 2) % MOD


class Solution:
    def maxNiceDivisors(self, n):
        M = 10**9 + 7

        # If n <= 3, return n directly
        if n <= 3:
            return n

        # Case 1: n is divisible by 3
        # Use only groups of 3 to maximize the product
        if n % 3 == 0:
            return pow(3, n // 3, M)

        # Case 2: Remainder is 1
        # Replace one group of 3 and the remaining 1
        # with two groups of 2 (2 * 2 = 4)
        if n % 3 == 1:
            return (pow(3, (n - 4) // 3, M) * 4) % M

        # Case 3: Remainder is 2
        # Use groups of 3 and one group of 2
        return (2 * pow(3, n // 3, M)) % M

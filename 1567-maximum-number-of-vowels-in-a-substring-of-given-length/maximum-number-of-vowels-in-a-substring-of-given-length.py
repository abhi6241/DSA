class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        l, c= 0, 0
        v = 'aeiou'
        res = []

        for r in range(len(s)):
            ch = s[r]
            if ch in v:
                c = c + 1
            if r - l + 1 == k:
                res.append(c)
                d = s[l]
                if d in v:
                    c = c - 1
                l = l + 1

        return max(res)

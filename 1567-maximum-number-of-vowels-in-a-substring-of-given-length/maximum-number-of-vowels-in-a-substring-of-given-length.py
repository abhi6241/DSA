class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels='aeiou'
        count=0

        for i in range(k):
            if s[i] in vowels:
                count= count + 1

        best = count

        for r in range(k,len(s)):
            if s[r] in vowels:
                count = count + 1
            if s[r-k] in vowels:
                count = count - 1

            best = max(best,count)
        return  best

            
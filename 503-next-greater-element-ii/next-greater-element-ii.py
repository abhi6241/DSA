class Solution:
    def nextGreaterElements(self, nums: list[int]) -> list[int]:
        n = len(nums)
        r = [-1] * n
        st = []

        for p in range(2 * n):
            while(st and nums[st[-1]] < nums[p % n]):
                d = st.pop()
                r[d] = nums[p % n]
            
            if(p < n):
                st.append(p % n)

        return r
class Solution:
    def canSeePersonsCount(self, heights: list[int]) -> list[int]:
        n = len(heights)
        r = [0] * n        # Array to store the count of visible people for each person
        st = []            # Monotonic decreasing stack storing indices of people to the right
        
        # Traverse the heights from right to left
        for p in range(n - 1, -1, -1):
            # Pop shorter people from the stack since the current person 'p' can see them,
            # and they will block any further views from people to the left.
            while(st and heights[st[-1]] < heights[p]):
                r[p] = r[p] + 1
                st.pop()
            
            # If the stack is not empty, current person 'p' can also see 
            # the next tallest person who limits their vision further right.
            if(st):
                r[p] = r[p] + 1
                
            # Add the current person's index to the stack
            st.append(p)
            
        return r

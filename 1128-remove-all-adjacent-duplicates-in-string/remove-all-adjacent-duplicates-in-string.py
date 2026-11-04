class Solution:
    def removeDuplicates(self, s: str) -> str:
        st = []
        for p in s:
            if(st and st[-1] == p):
                st.pop()
            else:
                st.append(p)
        return "".join(st)
class Solution:
    def removeDuplicates(self, s: str) -> str:
        st = []
        for p in s:
            # Remove the duplicate if it is repeated
            if(st and st[-1] == p):
                st.pop()
            # Push first char onto stack. Then subsequently peek the stack.
            # Only append if it's not repeating
            else:
                st.append(p)
                
        return "".join(st)
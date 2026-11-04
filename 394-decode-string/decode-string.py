class Solution:
    def decodeString(self, s: str) -> str:
        st = [] 
        num = 0
        curr = ""

        for p in s:
            if p.isdigit():
                num = num * 10 + int(p)
            elif p == "[":
                st.append([curr, num])
                curr = ""
                num = 0
            elif p.isalpha():
                curr = curr + p
            elif p == "]":
                prev, c = st.pop()
                curr = prev + curr * c

        return curr

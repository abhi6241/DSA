class Solution:
    def replaceElements(self, arr: list[int]) -> list[int]:
        max = -1
        for i in range(len(arr) - 1, -1, -1):
            d = arr[i]
            arr[i] = max
            if(d > max):
                max = d

        return arr
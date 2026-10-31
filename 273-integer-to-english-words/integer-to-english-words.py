
class Solution:
    def numberToWords(self, num: int) -> str:
        ones = ["", "One", "Two", "Three", "Four", "Five",
                "Six", "Seven", "Eight", "Nine", "Ten",
                "Eleven", "Twelve", "Thirteen", "Fourteen",
                "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                "Nineteen"]

        tens = ["", "", "Twenty", "Thirty", "Forty",
                "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]

        def convert(n):
            if n < 20:
                return ones[n]

            if n < 100:
                return tens[n // 10] + " " + ones[n % 10]

            return ones[n // 100] + " Hundred " + convert(n % 100)

        if num == 0:
            return "Zero"

        ans = ""

        if num >= 1000000000:
            ans += convert(num // 1000000000) + " Billion "
            num %= 1000000000

        if num >= 1000000:
            ans += convert(num // 1000000) + " Million "
            num %= 1000000

        if num >= 1000:
            ans += convert(num // 1000) + " Thousand "
            num %= 1000

        if num > 0:
            ans += convert(num)

        return " ".join(ans.split())

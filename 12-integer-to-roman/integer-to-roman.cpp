class Solution {
public:
    string intToRoman(int num) {

        // Roman numeral values in descending order
        // Includes special cases like 900 = CM, 4 = IV, etc.
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        // Corresponding Roman numeral symbols
        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string ans = "";

        // Check each Roman numeral value from largest to smallest
        for (int i = 0; i < values.size(); i++) {

            // Use the current value as many times as possible
            while (num >= values[i]) {

                // Add the corresponding Roman symbol
                ans += symbols[i];

                // Reduce num by that value
                num -= values[i];
            }
        }

        return ans;
    }
};
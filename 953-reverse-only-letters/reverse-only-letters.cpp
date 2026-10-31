class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            if (!isalpha(s[i])) {
                i++; // Skip non-letter from the left
            } else if (!isalpha(s[j])) {
                j--; // Skip non-letter from the right
            } else {
                swap(s[i], s[j]); // Both are letters, swap them
                i++;
                j--;
            }
        }
        return s;
    }
};

class Solution {
public:
    bool isAlphanumeric(char ch) {
        ch = tolower(ch);

        return (ch >= 'a' && ch <= 'z') ||
               (ch >= '0' && ch <= '9');
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {
            if (!isAlphanumeric(s[st])) {
                st++;
                continue;
            }

            if (!isAlphanumeric(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[st]) != tolower(s[end]))
                return false;

            st++;
            end--;
        }

        return true;
    }
};
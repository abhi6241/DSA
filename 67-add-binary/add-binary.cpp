class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0) {
                sum = sum + a[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum = sum + b[j] - '0';
                j--;
            }

            ans += (sum % 2) ? '1' : '0';
            // Equivalent:
            // ans.push_back((sum % 2) + '0');
            // push_back() appends a single character to the end of the string.
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
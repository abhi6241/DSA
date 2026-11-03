class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int c = 0, i = 0;

        for(i = 0; i < s.size(); i++) {
            if(c < spaces.size() && spaces[c] == i) {
                str.push_back(' ');
                c++;
            }
            str.push_back(s[i]);
        }

        return str;
    }
};
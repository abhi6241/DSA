class Solution {
public:
    int strStr(string haystack, string needle) {
        // size_t matches the return type of find() and safely handles string::npos.
        size_t pos = haystack.find(needle);
        return (pos == string::npos) ? -1 : pos;
    }
};
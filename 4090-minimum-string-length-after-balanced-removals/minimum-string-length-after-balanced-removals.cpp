class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int aCount = 0, bCount = 0;
        int size = s.length();

        for(int i = 0; i < size; i++) {
            if(s[i] == 'a') aCount++;
            else if(s[i] == 'b') bCount++;
        }
        
        if(aCount == 0 || bCount == 0) return size;

        return abs(aCount - bCount);
    }
};
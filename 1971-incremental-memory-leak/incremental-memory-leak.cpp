class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;

        // Check if the available memory is sufficient for the comsumption
        while (memory1 >= i || memory2 >= i) {
            // Check which memory is more
            if (memory1 >= memory2) {
                memory1 = memory1 - i;
            } else {
                memory2 = memory2 - i;
            }
            i++;
        }
        
        return {i, memory1, memory2};
    }
};

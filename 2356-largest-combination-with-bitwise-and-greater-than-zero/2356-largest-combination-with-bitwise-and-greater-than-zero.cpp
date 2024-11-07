class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;
        
        // Check each of the 24 bits (since constraints show numbers up to 10^7)
        for (int bit = 0; bit < 24; bit++) {
            int count = 0;
            // Count how many numbers have 1 at current bit position
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};

#include <vector>

class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num; // Calculate the maximum possible OR using all elements
        }
        
        int count = 0;
        int n = nums.size();
        int totalSubsets = 1 << n; // Total number of subsets is 2^n
        
        for (int i = 1; i < totalSubsets; ++i) { // Start from 1 to avoid empty subset
            int currentOr = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) { // Check if the j-th element is included in the i-th subset
                    currentOr |= nums[j];
                }
            }
            if (currentOr == maxOr) {
                ++count;
            }
        }
        
        return count;
    }
};

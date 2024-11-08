class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> answer(n);
        
        // Calculate the maximum possible value with maximumBit bits
        int maxValue = (1 << maximumBit) - 1;
        
        // Calculate running XOR
        int runningXor = 0;
        for(int num : nums) {
            runningXor ^= num;
        }
        
        // Process queries from end to beginning
        for(int i = 0; i < n; i++) {
            // Find k that maximizes runningXor XOR k
            // To maximize XOR, k should be such that runningXor XOR k = maxValue
            // Therefore, k = runningXor XOR maxValue
            answer[i] = runningXor ^ maxValue;
            
            // Remove the last element for next query
            if(i < n-1) {
                runningXor ^= nums[n-1-i];
            }
        }
        
        return answer;
    }
};

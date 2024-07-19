class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                count++;
            }
            if(count > maxcount)
            {
                maxcount = count;
            }
            if(nums[i] == 0)
            {
                count = 0;
            }
        }

        return maxcount;
    }
};
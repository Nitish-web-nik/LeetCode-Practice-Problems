class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsetCount = 1<<nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < subsetCount; ++i)
        {
            vector<int> subset;
            for(int j = 0; j < nums.size(); ++j)
            {
                if(i & (1<<j))
                {
                    subset.push_back(nums[j]);
                }
            }
            
            ans.push_back(subset);
        }
        return ans;

        
    }
};
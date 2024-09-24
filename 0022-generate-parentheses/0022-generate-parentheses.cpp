class Solution {
public:

    void backtrack(vector<string>& result, string curr, int open, int closed, int total)
    {
        if(curr.length() == 2 * total)
        {
            result.push_back(curr);
            return;
        }
        if(open < total)
        {
            backtrack(result, curr + '(', open + 1, closed, total);
        }
        if(closed < open)
        {
            backtrack(result, curr + ')', open, closed + 1, total);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans,"",0,0,n);

        return ans;
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int additions = 0;
        
        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (c == ')') {
                if (open > 0) {
                    open--;
                } else {
                    additions++;
                }
            }
        }
        
        additions += open;
        return additions;
    }
};

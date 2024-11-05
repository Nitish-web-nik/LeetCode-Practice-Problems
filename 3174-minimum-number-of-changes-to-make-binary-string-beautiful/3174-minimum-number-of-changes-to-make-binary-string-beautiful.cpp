class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int changes = 0;
        
        // Process string in blocks of size 2
        for(int i = 0; i < n; i += 2) {
            // If characters in the pair are different
            if(s[i] != s[i + 1]) {
                changes++;  // Need one change to make them same
            }
        }
        
        return changes;
    }
};

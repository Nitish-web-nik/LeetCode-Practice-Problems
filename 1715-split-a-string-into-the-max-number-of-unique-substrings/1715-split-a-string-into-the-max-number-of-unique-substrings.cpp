class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> usedSubstrs;
        return backtrack(s, usedSubstrs, 0);
    }
    
private:
    int backtrack(const string &s, unordered_set<string> &usedSubstrs, int start) {
        if (start == s.size()) return 0;

        int maxSplit = 0;
        for (int end = start + 1; end <= s.size(); ++end) {
            string substr = s.substr(start, end - start);
            if (usedSubstrs.find(substr) == usedSubstrs.end()) {
                usedSubstrs.insert(substr);
                maxSplit = max(maxSplit, 1 + backtrack(s, usedSubstrs, end));
                usedSubstrs.erase(substr);
            }
        }
        return maxSplit;
    }
};

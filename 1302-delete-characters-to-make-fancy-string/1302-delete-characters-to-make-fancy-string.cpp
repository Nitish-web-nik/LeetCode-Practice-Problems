class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // If the current character is different from the previous or 
            // if we have fewer than 2 consecutive same characters
            if (result.size() < 2 || !(s[i] == result.back() && s[i] == result[result.size() - 2])) {
                result += s[i];
            }
        }
        
        return result;
    }
};

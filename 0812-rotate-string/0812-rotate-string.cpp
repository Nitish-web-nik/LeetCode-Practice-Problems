class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths are the same
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Double the original string s
        string doubled = s + s;

        // Check if goal is a substring of the doubled string
        return doubled.find(goal) != string::npos;
    }
};

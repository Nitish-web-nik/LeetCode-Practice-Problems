class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        int i = 0;

        while (i < n) {
            char currentChar = word[i];
            int count = 0;

            // Count consecutive characters, limiting to a maximum of 9
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }

            // Append the count and the character to the result
            comp += to_string(count) + currentChar;
        }

        return comp;
    }
};

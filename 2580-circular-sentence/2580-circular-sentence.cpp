class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        int num_words = words.size();
        if (num_words == 0) return false;

        for (int i = 0; i < num_words; ++i) {
            string current_word = words[i];
            string next_word = words[(i + 1) % num_words]; // Wrap around to the first word
            if (current_word.back() != next_word.front()) {
                return false;
            }
        }

        return true;
    }
};

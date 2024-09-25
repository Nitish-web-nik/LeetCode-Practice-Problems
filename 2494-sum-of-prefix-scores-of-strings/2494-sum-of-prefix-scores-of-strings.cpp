

class TrieNode {
public:
    int count; // To keep track of how many words share this prefix
    unordered_map<char, TrieNode*> children;

    TrieNode() : count(0) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;
        }
    }

    // Calculate the prefix scores for a given word
    int calculatePrefixScore(const std::string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            if (!node->children[c]) return score; // If the prefix does not exist
            node = node->children[c];
            score += node->count; // Add the count of words with this prefix
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        // Step 1: Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }

        // Step 2: Calculate the prefix scores for each word
        std::vector<int> answer;
        for (const string& word : words) {
            answer.push_back(trie.calculatePrefixScore(word));
        }

        return answer;
    }
};

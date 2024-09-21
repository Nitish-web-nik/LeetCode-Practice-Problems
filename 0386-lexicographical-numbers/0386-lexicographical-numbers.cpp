class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;
        for (int i = 0; i < n; ++i) {
            // Add the current number to the result
            result.push_back(current);
            // If multiplying current by 10 is less than or equal to n, keep going to the next depth
            if (current * 10 <= n) {
                current *= 10;
            } else {
                // When current reaches the end of a depth (a multiple of 10 - 1) or n
                // We go back to the closest ancestor which can have a right sibling
                // and increment it by 1 in the lexicographical sequence
                while (current % 10 == 9 || current + 1 > n) {
                    current /= 10;
                }
                ++current;
            }
        }
        return result; // Return the list in lexicographically increasing order
    }
};

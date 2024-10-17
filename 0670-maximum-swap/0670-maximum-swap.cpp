class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string to easily access individual digits
        string numStr = to_string(num);
        int n = numStr.size();

        // Store the last occurrence of each digit 0-9
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }

        // Try to find the first pair of digits to swap
        for (int i = 0; i < n; ++i) {
            // Check for a larger digit to swap with
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap digits
                    swap(numStr[i], numStr[last[d]]);
                    // Convert string back to integer and return the result
                    return stoi(numStr);
                }
            }
        }

        // Return the original number if no swap can enhance the value
        return num;
    }
};

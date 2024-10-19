class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: The first string S1 is "0".
        if (n == 1) {
            return '0';
        }
        
        // Calculate the length of the Sn string
        int length = (1 << n) - 1; // Same as 2^n - 1
        
        // Find the middle point of the string
        int mid = length / 2 + 1;
        
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            // If k is in the left part, it is equivalent to finding it in Sn-1
            return findKthBit(n - 1, k);
        } else {
            // If k is in the right part, it corresponds to a reversed and inverted Sn-1
            int correspondingK = length - k + 1;
            char bit = findKthBit(n - 1, correspondingK);
            return bit == '0' ? '1' : '0';
        }
    }
};

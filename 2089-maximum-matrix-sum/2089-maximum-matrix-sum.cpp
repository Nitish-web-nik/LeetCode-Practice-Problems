class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;    // To store the total absolute sum of all elements
        int minAbsVal = INT_MAX;   // To store the smallest absolute value in the matrix
        int negativeCount = 0;     // To count the total number of negative elements

        int n = matrix.size();     // Matrix size (n x n)

        // Traverse the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = matrix[i][j];
                totalSum += abs(val); // Add the absolute value to the total sum
                minAbsVal = min(minAbsVal, abs(val)); // Update the smallest absolute value
                if (val < 0) negativeCount++; // Count negative elements
            }
        }

        // If the number of negative elements is odd, subtract twice the smallest absolute value
        // Otherwise, use the full total sum
        if (negativeCount % 2 == 1) {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
};

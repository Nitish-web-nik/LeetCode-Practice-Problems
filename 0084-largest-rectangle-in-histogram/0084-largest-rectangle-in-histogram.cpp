class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Add a 0 at the end to handle remaining elements
        heights.push_back(0);
        int n = heights.size();
        stack<int> indices;
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            // Process all bars that are taller than current bar
            while(!indices.empty() && heights[i] < heights[indices.top()]) {
                int height = heights[indices.top()];
                indices.pop();
                
                // Calculate width based on the next smaller element on both sides
                int width = indices.empty() ? i : (i - indices.top() - 1);
                
                // Update maximum area
                maxArea = max(maxArea, height * width);
            }
            indices.push(i);
        }
        
        // Remove the added 0 to restore original array
        heights.pop_back();
        return maxArea;
    }
};

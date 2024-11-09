class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        // Iterate through all bars, including one extra iteration for remaining elements
        for (int i = 0; i <= n; i++) {
            // Current height is 0 if we're past the last bar
            int currHeight = (i == n) ? 0 : heights[i];
            
            // While stack is not empty and current height is less than height at top of stack
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // Width is distance from current position to previous element in stack
                int width = st.empty() ? i : i - st.top() - 1;
                
                // Update maximum area if current rectangle is larger
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};

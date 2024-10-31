class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort both robots and factories positions
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int m = robot.size(), n = factory.size();
        // dp[i][j] represents min distance to repair first i robots using first j factories
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
        
        // Base case - no robots to repair
        dp[0][0] = 0;
        
        // For each number of robots
        for(int i = 0; i <= m; i++) {
            // For each factory
            for(int j = 1; j <= n; j++) {
                // If no robots, distance is 0
                if(i == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                
                // Try assigning k robots to current factory j
                long long cost = 0;
                // Consider previous state without using current factory
                if(dp[i][j-1] != LLONG_MAX)
                    dp[i][j] = dp[i][j-1];
                
                // Try assigning k robots to current factory
                for(int k = 1; k <= min(i, factory[j-1][1]); k++) {
                    // Add distance for current robot
                    cost += abs((long long)robot[i-k] - factory[j-1][0]);
                    
                    // If we can assign i-k robots to j-1 factories
                    if(dp[i-k][j-1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i-k][j-1] + cost);
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};

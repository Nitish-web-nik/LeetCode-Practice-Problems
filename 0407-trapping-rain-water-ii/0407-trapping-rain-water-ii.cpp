class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        
        // Use priority queue to store cells (height, row, col)
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>,
                      greater<pair<int, pair<int, int>>>> pq;
                      
        // Create visited array
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Add border cells to priority queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        // Direction arrays for 4-directional movement
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        int result = 0;
        int maxHeight = 0;
        
        // Process cells starting from lowest height
        while (!pq.empty()) {
            int height = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            maxHeight = max(maxHeight, height);
            
            // Check all 4 directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                
                // Check bounds and visited status
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                    && !visited[newRow][newCol]) {
                    
                    visited[newRow][newCol] = true;
                    
                    // If current cell is lower than maxHeight, it can trap water
                    if (heightMap[newRow][newCol] < maxHeight) {
                        result += maxHeight - heightMap[newRow][newCol];
                    }
                    
                    pq.push({heightMap[newRow][newCol], {newRow, newCol}});
                }
            }
        }
        
        return result;
    }
};

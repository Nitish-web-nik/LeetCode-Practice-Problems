class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns
        
        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Priority Deque for 0-1 BFS (stores pair of {removed obstacles, {row, column}})
        deque<pair<int, pair<int, int>>> dq;
        dq.push_front({0, {0, 0}}); // Start from the top-left corner with 0 obstacles removed
        
        // Distance array to track minimum obstacles removed to reach each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        while (!dq.empty()) {
            auto [obstacles, cell] = dq.front();
            dq.pop_front();
            
            int x = cell.first, y = cell.second;
            
            // If we reached the bottom-right corner, return the result
            if (x == m - 1 && y == n - 1) {
                return obstacles;
            }
            
            // Explore neighbors
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                
                // Check bounds
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newObstacles = obstacles + grid[nx][ny];
                    
                    // If a shorter path is found, update and process the neighbor
                    if (newObstacles < dist[nx][ny]) {
                        dist[nx][ny] = newObstacles;
                        
                        // Push based on whether it is an obstacle or not
                        if (grid[nx][ny] == 0) {
                            dq.push_front({newObstacles, {nx, ny}});
                        } else {
                            dq.push_back({newObstacles, {nx, ny}});
                        }
                    }
                }
            }
        }
        return -1; // This line will never be reached as the bottom-right corner is always reachable
    }
};

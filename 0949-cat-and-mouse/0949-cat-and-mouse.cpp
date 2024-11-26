class Solution {

public:

    int catMouseGame(vector<vector<int>>& graph) {

        int n = graph.size();
        // 3D array to store the state: [mouse][cat][turn]
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(3, 0)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(3, 0)));

        // Initialize degrees
        for (int m = 0; m < n; ++m) {
            for (int c = 0; c < n; ++c) {
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                // Remove invalid moves where cat moves to node 0 (the hole)
                if (find(graph[c].begin(), graph[c].end(), 0) != graph[c].end()) {
                    degree[m][c][2]--;
                }
            }
        }

        queue<tuple<int, int, int>> q;

        // Initialize winning positions
        for (int i = 0; i < n; ++i) {
            for (int t = 1; t <= 2; ++t) {
                if (i != 0) {
                    color[0][i][t] = 1; // Mouse wins by reaching the hole
                    q.push({0, i, t});
                }
                color[i][i][t] = 2; // Cat wins by catching the mouse
                q.push({i, i, t});
            }
        }

        // Helper function to get previous states
        auto getPrevStates = [&](int m, int c, int t) {
            vector<tuple<int, int, int>> prevStates;
            if (t == 2) {
                // Previous turn was Mouse's move
                for (int m_prev : graph[m]) {
                    prevStates.emplace_back(m_prev, c, 1);
                }
            } else {
                // Previous turn was Cat's move
                for (int c_prev : graph[c]) {
                    if (c_prev == 0) continue; // Cat cannot move to the hole
                    prevStates.emplace_back(m, c_prev, 2);
                }
            }
            return prevStates;
        };

        // Perform BFS to determine the outcome
        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int result = color[m][c][t];

            for (auto [m_prev, c_prev, t_prev] : getPrevStates(m, c, t)) {
                if (color[m_prev][c_prev][t_prev] != 0) continue;
                if (t_prev == result) {
                    color[m_prev][c_prev][t_prev] = result;
                    q.push({m_prev, c_prev, t_prev});
                } else {
                    degree[m_prev][c_prev][t_prev]--;
                    if (degree[m_prev][c_prev][t_prev] == 0) {
                        color[m_prev][c_prev][t_prev] = result;
                        q.push({m_prev, c_prev, t_prev});
                    }
                }
            }
        }

        int outcome = color[1][2][1];
        return outcome == 0 ? 0 : (outcome == 1 ? 1 : 2);
    }

};

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Step 1: Initialize an in-degree array to count indegrees of each node (team)
        vector<int> inDegree(n, 0);

        // Step 2: Calculate in-degrees for each node based on the edges
        for (auto& edge : edges) {
            inDegree[edge[1]]++;
        }

        // Step 3: Find the nodes (teams) with in-degree 0
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                // If there is already a champion candidate, return -1 (not unique)
                if (champion != -1) {
                    return -1;
                }
                champion = i;
            }
        }

        // Step 4: Validate if the champion candidate is unique
        // If no team has in-degree 0 or if more than one candidate exists, return -1
        return champion;
    }
};

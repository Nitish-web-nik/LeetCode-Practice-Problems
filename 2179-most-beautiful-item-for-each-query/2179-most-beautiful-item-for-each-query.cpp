class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items based on price, then by beauty in descending order
        sort(items.begin(), items.end());
        
        // Preprocess to accumulate maximum beauty for each maximum price
        vector<pair<int, int>> maxBeau;
        int maxBeauty = 0;
        for (const auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            maxBeau.emplace_back(item[0], maxBeauty);
        }
        
        vector<int> results;
        
        for (const int& query : queries) {
            // Find the rightmost item price which is <= query using binary search
            auto it = upper_bound(maxBeau.begin(), maxBeau.end(), make_pair(query, INT_MAX));
            if (it == maxBeau.begin()) {
                results.push_back(0); // No valid items
            } else {
                --it; // Get the last valid item
                results.push_back(it->second);
            }
        }
        
        return results;
    }
};

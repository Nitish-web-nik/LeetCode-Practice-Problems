class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Define the target string board: [[1,2,3],[4,5,0]] => "123450"
        string target = "123450";
        
        // Convert the initial board to a string for easier manipulation and comparison
        string start = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start += to_string(board[i][j]);
            }
        }
        
        // Define valid moves for every index in this 1D representation of a 2x3 board
        vector<vector<int>> neighbors = {
            {1, 3},       // Moves for index 0
            {0, 2, 4},    // Moves for index 1
            {1, 5},       // Moves for index 2
            {0, 4},       // Moves for index 3
            {1, 3, 5},    // Moves for index 4
            {2, 4}        // Moves for index 5
        };
        
        // Breadth-First Search (BFS) setup
        queue<pair<string, int>> q;        // Pair<string, steps> to track board state and move count
        unordered_set<string> visited;    // To prevent revisiting the same state
        
        q.push({start, 0});               // Push the initial state with 0 moves
        visited.insert(start);            // Mark it visited
        
        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();
            
            // If the current state matches the target, return the number of steps
            if (current == target) {
                return steps;
            }
            
            // Find the position of '0' in the current board
            int zeroPos = current.find('0');
            
            // Try all valid moves
            for (int neighbor : neighbors[zeroPos]) {
                string nextState = current;
                swap(nextState[zeroPos], nextState[neighbor]);  // Swap '0' with its neighbor
                
                // If the new state hasn't been visited, process it
                if (visited.find(nextState) == visited.end()) {
                    visited.insert(nextState);
                    q.push({nextState, steps + 1});
                }
            }
        }
        
        // If the loop finishes without finding the target, return -1 (unsolvable)
        return -1;
    }
};

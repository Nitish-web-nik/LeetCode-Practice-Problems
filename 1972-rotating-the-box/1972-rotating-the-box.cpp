#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();    // Number of rows
        int n = box[0].size(); // Number of columns
        
        // Simulate the gravity for each row
        for (int i = 0; i < m; ++i) {
            int emptySlot = n - 1; // Pointer for the last available empty slot in the row
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '#') {
                    // Move the stone to the empty slot
                    box[i][j] = '.';
                    box[i][emptySlot--] = '#';
                } else if (box[i][j] == '*') {
                    // If an obstacle is encountered, the empty slot resets to just before the obstacle
                    emptySlot = j - 1;
                }
            }
        }
        
        // Rotate the box 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};

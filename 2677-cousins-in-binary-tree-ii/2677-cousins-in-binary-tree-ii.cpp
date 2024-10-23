#include <unordered_map>
#include <queue>

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        std::queue<std::pair<TreeNode*, int>> q;  // pair of node and its depth
        std::unordered_map<int, int> levelSumMap;
        
        q.push({root, 0});

        // First pass to calculate the sum of all levels
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            levelSumMap[depth] += node->val;

            if (node->left) {
                q.push({node->left, depth + 1});
            }
            if (node->right) {
                q.push({node->right, depth + 1});
            }
        }

        q.push({root, 0});

        // Second pass to update each node's value
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            
            int siblingsSum = 0;
            if (node->left) siblingsSum += node->left->val;
            if (node->right) siblingsSum += node->right->val;

            if (node->left) {
                node->left->val = levelSumMap[depth + 1] - siblingsSum;
                q.push({node->left, depth + 1});
            }
            if (node->right) {
                node->right->val = levelSumMap[depth + 1] - siblingsSum;
                q.push({node->right, depth + 1});
            }
        }

        root->val = 0;  // The root can't have cousins

        return root;
    }
};

class Solution {
private:
    TreeNode* prev = nullptr;
    
public:
    void flatten(TreeNode* root) {
        // Base case: if root is null, return
        if (root == nullptr) return;
        
        // Store the right and left subtrees
        TreeNode* rightSubtree = root->right;
        TreeNode* leftSubtree = root->left;
        
        // If we have a previous node, connect it to current node
        if (prev != nullptr) {
            prev->right = root;
            prev->left = nullptr;
        }
        
        // Update prev to current node
        prev = root;
        
        // First process left subtree
        flatten(leftSubtree);
        // Then process right subtree
        flatten(rightSubtree);
        
        // Set left pointer to null
        root->left = nullptr;
    }
};

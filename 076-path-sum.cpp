/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool traverse(TreeNode*root, int currentSum, int &targetSum) {
        if(!root) return false;
        
        currentSum += root->val;
        
        if(!root->left && !root->right) return currentSum == targetSum;
        
        return traverse(root->left, currentSum, targetSum) || traverse(root->right, currentSum, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, 0, targetSum);
    }
};
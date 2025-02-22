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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int cur, int &res) {
        if(root->left == nullptr && root->right == nullptr) {
            res += cur*10 + root->val;
            return;
        }
        if(root->left != nullptr) {
            dfs(root->left, cur*10 + root->val, res);
        }
        if(root->right != nullptr) {
            dfs(root->right, cur*10 + root->val, res);
        }
    }
};
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
    void invert(TreeNode* root) {
        if(root == nullptr) return;
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr ) return true;
        else if(p == nullptr || q == nullptr) return false;
        else if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        invert(left);
        
        return isSameTree(left, right);
    }
};
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
    void traverse(TreeNode* root, vector<TreeNode*> &preorderList) {
        if(root == nullptr) return;
        preorderList.push_back(root);
        traverse(root->left, preorderList);
        traverse(root->right, preorderList);
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> preorderList;
        traverse(root, preorderList);
        
        for(int i = 0; i < (int)preorderList.size() - 1; i++) {
            preorderList[i]->left = nullptr;
            preorderList[i]->right = preorderList[i+1];
        }
        
        
    }
};
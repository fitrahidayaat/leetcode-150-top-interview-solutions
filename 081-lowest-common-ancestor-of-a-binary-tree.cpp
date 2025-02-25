/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
      map<TreeNode*, TreeNode*> parent;
      void dfs(TreeNode* root) {
          if(root == nullptr) return;
          if(root->left != nullptr) {
              parent[root->left] = root;
          }
          if(root->right != nullptr) {
              parent[root->right] = root;
          }
          dfs(root->left);
          dfs(root->right);
      }
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          dfs(root);
          map<TreeNode*, bool> mp;
          while(p != root) {
              mp[p] = true;
              p = parent[p];
          }
          while(q != root) {
              if(mp[q]) return q;
              q = parent[q];
          }
  
          return root;
      }
  };
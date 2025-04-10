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
      vector<double> averageOfLevels(TreeNode* root) {
          vector<vector<int>> x;
          queue<pair<TreeNode*, int>> q;
          q.push({root, 0});
          while(!q.empty()) {
              TreeNode* p = q.front().first;
              int level = q.front().second;
              q.pop();
              if(level == x.size()) {
                  x.push_back({p->val});
              } else {
                  x[level].push_back(p->val);
              }
              if(p->right != nullptr) {
                  q.push({p->right, level+1});
              }
              if(p->left != nullptr) {
                  q.push({p->left, level+1});
              }
          }
  
          vector<double> ans;
          for(vector<int> &k:x) {
              long long sum = 0;
              for(int y: k) {
                  sum += y;
              }
  
              ans.push_back(sum*1.0/k.size());
          }
          return ans;
      }
  };
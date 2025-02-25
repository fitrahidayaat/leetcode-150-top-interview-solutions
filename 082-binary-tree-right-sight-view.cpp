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
      vector<int> rightSideView(TreeNode* root) {
          if(root == nullptr) return {};
  
          queue<pair<TreeNode*, int>> q;
          q.push({root, 0});
          vector<int> result;
          
          while(!q.empty()) {
              TreeNode* curNode = q.front().first;
              int level = q.front().second;
              q.pop();
  
              if(level == result.size()) {
                  result.push_back(curNode->val);
              } else {
                  result[level] = curNode->val;
              }
  
              if(curNode->left != nullptr) {
                  q.push({curNode->left, level + 1});
              }
              if(curNode->right != nullptr) {
                  q.push({curNode->right, level + 1});
              }
          }
  
          return result;
      }
  };
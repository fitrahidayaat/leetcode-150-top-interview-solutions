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
class BSTIterator {
  public:
      vector<TreeNode*> parents;
      BSTIterator(TreeNode* root) {
          parents.push_back(root);
      }
  
      int next() {
          TreeNode* cur = parents.back();
          while(cur != nullptr) {
              if(cur->right != nullptr) {
                  TreeNode* x = parents.back();
                  parents.pop_back();
                  parents.push_back(cur->right);
                  parents.push_back(x);
                  cur->right = nullptr;
              }
              parents.push_back(cur->left);
              cur->left = nullptr;
              cur = parents.back();
          }
  
          parents.pop_back();
          int ans = parents.back()->val;
          parents.pop_back();
          return ans;
      }
      
      bool hasNext() {
          return !parents.empty();
      }
  };
  
  /**
   * Your BSTIterator object will be instantiated and called as such:
   * BSTIterator* obj = new BSTIterator(root);
   * int param_1 = obj->next();
   * bool param_2 = obj->hasNext();
   */
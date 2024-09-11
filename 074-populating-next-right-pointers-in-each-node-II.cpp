/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        vector<vector<Node*>> v;
        
        while(!q.empty()) {
            pair<Node*, int> node = q.front();
            q.pop();
            
            if(node.first == NULL) {
                continue;
            }
            
            if(node.second >= v.size()) {
                v.push_back({node.first});
            } else {
                v[node.second].push_back(node.first);
            }
            
            q.push({node.first->left, node.second + 1});
            q.push({node.first->right, node.second + 1});
        }
        
        for(vector<Node*> x:v) {
            for(int i = 0; i < x.size() - 1; i++) {
                x[i]->next = x[i+1];
            }
            x.back()->next = NULL;
        }
        
        return root;
    }
};
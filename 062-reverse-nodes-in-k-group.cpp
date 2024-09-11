/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* p = head;
        vector<vector<ListNode*>> v;
        v.push_back({});
        while(p != nullptr) {
            if(v.back().size() < k) {
                v.back().push_back(p);
            } else {
                v.push_back({p});
            }
            p = p->next;
        } 
        
        for(int i = 0; i < (int)v.size(); i++) {
            if(v[i].size() == k) {
                for(int j = 1; j < k; j++) {
                    v[i][j]->next = v[i][j-1];
                }
                if(i < v.size() - 1) {
                    if(v[i+1].size() != k) {
                        v[i][0]->next = v[i+1][0];
                    } else {
                        v[i][0]->next = v[i+1].back();
                    }
                } else {
                    v[i][0]->next = nullptr;
                }
            }
        }
        
        return v[0].back();
    }
};
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> v1, v2;
        ListNode* p = head;
        
        while(p != nullptr) {
            if(p->val < x) {
                v1.push_back(p);
            } else {
                v2.push_back(p);
            }
            p = p->next;
        }

        for(int i = 0; i < (int)v1.size() - 1; i++) {
            v1[i]->next = v1[i+1];
        }
        
        for(int i = 0; i < (int)v2.size() - 1; i++) {
            v2[i]->next = v2[i+1];
        }


        if(v1.empty() && v2.empty()) return head;
        else if(v1.empty()) {
            return v2[0];
        } else if(v2.empty()) {
            return v1[0];
        } else {
            v1.back()->next = v2[0];
            v2.back()->next = nullptr;
            return v1[0];
        }
    }
};
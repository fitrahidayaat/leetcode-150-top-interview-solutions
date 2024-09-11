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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> v;
        ListNode *p = head;
        while(p != NULL) {
            v.push_back(p);
            p = p->next;
        }
        
        while(left < right) {
            swap(v[left-1]->val, v[right-1]->val);
            left++;
            right--;
        }
        
        return v[0];
        
        
    }
};
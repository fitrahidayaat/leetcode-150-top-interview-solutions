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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;
        
        ListNode* p = head;
        ListNode* before = nullptr;
        while(p != nullptr) {
            m[p->val]++;
            p = p->next;
        }
        
        p = head;
        while(p != nullptr) {
            if(m[p->val] > 1) {
                if(before == nullptr) {
                    head = p->next;
                } else {
                    before->next = p->next;
                }
            } else {
                before = p;
            }

            p = p->next;
        }
        
        return head;
    }
};
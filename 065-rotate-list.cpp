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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr) return head;
        ListNode* p = head;
        ListNode* before;
        ListNode* end;
        int len = 0;
        while(p != nullptr) {
            len++;
            end = p;
            p = p->next;
        }
        end->next = head;
        
        p = head;
        before = nullptr;
        int i = 0;
        int target = len - k%len;
        while(i < target) {
            before = p;
            p = p->next;
            
            i++;
        }
        
        before->next = nullptr;
        return p;
        
        
    }
};
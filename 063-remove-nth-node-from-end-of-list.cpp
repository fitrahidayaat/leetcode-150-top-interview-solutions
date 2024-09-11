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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        int len = 0;
        while(p != nullptr) {
            p = p->next;
            len++;
        }
        
        int target = len - n;
        int i = 0;
        p = head;
        ListNode *before = nullptr;
        while(i < target) {
            i++;
            before = p;
            p = p->next;
        }

        if(before != nullptr) {
            before->next = p->next;
            p->next = nullptr;
        } else {
            head = p->next;
        }
        
            
        return head;
    }
};
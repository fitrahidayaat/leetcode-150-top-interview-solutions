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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l3 = new ListNode();
        ListNode* res = l3;
        while(l1 != nullptr || l2 != nullptr) {
            int val = 0;
            if(l1 == nullptr) {
                val += (carry + l2->val)%10;
                if(carry + l2->val > 9) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                l2 = l2->next;
            } else if(l2 == nullptr) {
                val += (carry + l1->val)%10;
                if(carry + l1->val > 9) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                l1 = l1->next;
            } else {
                val += (carry +l1->val + l2->val)%10;
                if(carry + l1->val + l2->val > 9) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                l1 = l1->next;
                l2 = l2->next;
            }

            l3->next = new ListNode(val);
            l3 = l3->next;
        }
        if(carry) l3->next = new ListNode(carry);
        return res->next;
        
        
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *hare, *tortoise;
        tortoise = head;
        hare = head->next;
        
        while(hare != tortoise && hare != NULL && tortoise != NULL) {
            tortoise = tortoise->next;
            hare = hare->next;
            if(hare == NULL) break;
            hare = hare->next;
        }
        
        return hare == tortoise;
    }
};
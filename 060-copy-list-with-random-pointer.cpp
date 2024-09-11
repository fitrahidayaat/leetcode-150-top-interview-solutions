/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node* newList = new Node(head->val);
        Node* p = head->next;
        vector<Node*> v = {newList};
        
        while(p != NULL) {
            newList->next = new Node(p->val);
            newList = newList->next;
            v.push_back(newList);
            p = p->next;
        }
        
        p = head;
        int i = 0;
        while(p != NULL) {
            Node *q = head;
            int j = 0;
            while(q != NULL && q != p->random) {
                q = q->next;
                j++;
            }
            
            if(q == NULL) {
                v[i]->random = NULL;
            } else {
                v[i]->random = v[j];
            }
            
            p = p->next;
            i++;
        }
        
        
        return v[0];
    }
};
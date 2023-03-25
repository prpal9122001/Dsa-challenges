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
        if(head == NULL) return head;
        Node* ptr = head;
        while(ptr != NULL){
            Node* node = new Node (ptr->val, ptr->next, NULL);
            ptr->next = node;
            ptr = node->next;
        }
        Node* oldptr = head;
        while (oldptr != NULL){
            oldptr->next->random = oldptr->random == NULL ? NULL : oldptr->random->next;
            oldptr= oldptr->next->next;
        }
        oldptr = head;
        Node* newptr = head->next;
        Node* newHead = newptr;
        while(oldptr != NULL){
            oldptr->next=newptr->next;
            newptr->next = newptr->next != NULL ? newptr->next->next : NULL;
            oldptr = oldptr->next;
            newptr = newptr->next;
        }
        return newHead;
    }
};

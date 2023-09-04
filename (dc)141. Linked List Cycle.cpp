//https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2023-09-04
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
        auto rabbit=head,tortoise=head;
        while(rabbit && rabbit->next){
        rabbit=rabbit->next->next;
        tortoise=tortoise->next;
        if(rabbit==tortoise){
            return true;
        }
    }
    return false;
  }
};

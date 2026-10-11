/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = head,*h1 = head, *h2;
        if(tmp!=nullptr){
            tmp = tmp->next;
            h1->next = nullptr;
        }
        while(tmp!=nullptr){
            h2 = tmp;
            tmp = tmp->next;
            h2->next = h1;
            h1 = h2;
            // cerr<<"p\n";
        }
        return h1;
    }
};

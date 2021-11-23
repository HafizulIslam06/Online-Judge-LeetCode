/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* third = NULL;
        ListNode* last = NULL;

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(first->val <= second->val){
            third = last = first;
            first = first->next;
            last->next = NULL;
        }

        else{
            third = last = second;
            second = second->next;
            last->next=NULL;
        }

        while(first!= NULL && second!=NULL){

            if(first->val <= second->val){
                last->next = first;
                last = first;
                first = first->next;
                last->next = NULL;
            }

            else{
                last->next = second;
                last = second;
                second = second->next;
                last->next = NULL;
            }
        }

        if(first!=NULL) last->next = first;
        else if(second!=NULL) last->next = second;

        return third;

    }
};

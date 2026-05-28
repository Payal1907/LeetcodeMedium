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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesser = new ListNode();
        ListNode* greater = new ListNode();
        ListNode* less = lesser; //pointer
        ListNode* more = greater; //pointer
        ListNode* temp = head;
        while(temp){
            if(temp->val<x){
                less->next=new ListNode(temp->val);
                less=less->next;
            }
            else{
                more->next=new ListNode(temp->val);
                more=more->next;
            }
            temp=temp->next;
        }
        less->next=greater->next;
        return lesser->next;
    }
};
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
    void reorderList(ListNode* head) {
    if(!head||!head->next||!head->next->next) return;
    ListNode* fast=head;
    ListNode* slow=head;
    //pehle hm middle element dhundhenge
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    } 
    //second half ko reverse krde
    ListNode* prev=nullptr;
    ListNode* ptr=slow->next;
    while(ptr)
    {
        ListNode* nxt = ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=nxt;
    }
    slow->next=nullptr; //cut both halves
    //now merging both of them
    ListNode* first=head;
    ListNode* second=prev;
    while(second)
    {
        ListNode* t1=first->next;
        ListNode* t2=second->next;
        first->next=second;
        second->next=t1;
        first=t1;
        second=t2;
    }
    }
};
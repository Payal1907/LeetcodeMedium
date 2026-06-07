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
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<=l2->val){
            l1->next=mergeLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    return mergeLists(list1,list2);
    ListNode* l1 = list1;
    ListNode* l2 = list2;
    ListNode* res = new ListNode();
    ListNode* ans=res;
    while(l1&&l2)
    {
        if(l1->val<l2->val) 
        {
            ans->next=l1;
            l1=l1->next;
        }
        else
        {
            ans->next=l2;
            l2=l2->next;
        }
        ans=ans->next;
    } 
    ans->next = l1 ? l1 : l2;
    return res->next;  
    }
};
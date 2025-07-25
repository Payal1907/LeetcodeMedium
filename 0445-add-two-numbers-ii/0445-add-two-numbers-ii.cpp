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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=nullptr;
        while(head!=nullptr)
        {
            ListNode* next = head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        while(l1||l2)
        {
            int sum = carry;
            if(l1) sum=sum+l1->val;
            if(l2) sum=sum+l2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry=sum/10;
            curr->next=newNode;
            curr=curr->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        } 
        if(carry)
        {
            ListNode* newNode = new ListNode(carry);
            curr->next=newNode;
        }
        return reverseList(dummy->next);   
    }
};
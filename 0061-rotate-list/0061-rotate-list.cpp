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
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* temp = head;
    int n=1;
    while(temp->next!=nullptr)
    {
        n++;
        temp=temp->next;
    } //yaha tk elements count kr rhi hai
    temp->next=head; //phir circular list bnaya
    k=k%n; 
    k=n-k; //phir n-k tk chlaya
    temp=head; //matters
    while(--k)
    {
        temp=temp->next;
    } //phir waha se khatam kr diya
    ListNode* curr = temp->next;
    head=curr;
    temp->next=nullptr;
    return head;
    }
};
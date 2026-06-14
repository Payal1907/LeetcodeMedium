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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nxt = head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head; ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = reverseList(slow);
        int ans = 0;
        while(second){
            ans=max(ans, head->val+second->val);
            head=head->next;
            second=second->next;
        }
        return ans;
        
    }
};
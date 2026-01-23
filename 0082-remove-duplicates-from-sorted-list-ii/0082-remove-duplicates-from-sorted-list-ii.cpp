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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* copy = new ListNode(-1);
        copy->next=head;
        ListNode* temp = copy;
        ListNode* curr = head;
        while(curr && curr->next){
            if(curr->val==curr->next->val){
                while(curr->next && curr->val==curr->next->val){
                curr=curr->next;    
            }
            temp->next=curr->next;
            }
            else{
                temp=temp->next;
            }
            //temp to hmesha piche hi hoga curr se
            //curr check krega kaha tk duplicates hai
            //temp pcihe rhega uske calculation ka wait krega
            //phir temp update hoga
            //pr agr duplicates hai hi nai to temp bhi khudko update krega
            //aur curr bhi
            curr=curr->next;
        } 
        return copy->next;     
    }
};
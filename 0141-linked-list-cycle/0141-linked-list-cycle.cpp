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
        if(head==NULL) return false;
    map<ListNode*,bool> vis;
    ListNode* temp = head;
    while(temp!=NULL){
        if(vis[temp]) return true;
        vis[temp]=true;
        temp=temp->next;
    }
    return false;

    // while(p && p->next){
    //     q=q->next;
    //     p=p->next->next;
    //     if(p==q) return true;
    // }  
    // return false;  
    }
};
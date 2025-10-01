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
    stack<ListNode*> st;
    ListNode* curr = head;
    while(curr)
    {
        st.push(curr);
        curr=curr->next;
    }
    int n = st.size();
    curr=head;
    for(int i=0;i<n/2;i++)
    {
        ListNode* node = st.top();
        st.pop();
        node->next=curr->next;
        curr->next=node;
        curr=node->next;
    }
    curr->next=nullptr;
    }
};
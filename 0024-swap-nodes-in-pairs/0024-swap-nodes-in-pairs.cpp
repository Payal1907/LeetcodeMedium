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
    ListNode* swapPairs(ListNode* head) {
    if(!head||!head->next) return head;
    vector<int> arr;
    ListNode* temp = new ListNode();
    ListNode* copy = temp;
    while(head){
        arr.push_back(head->val);
        head=head->next;
    }  
    for(int i=0;i<arr.size()-1;i+=2){
        std::swap(arr[i],arr[i+1]);
    } 
    for(int i=0;i<arr.size();i++){
        temp->next=new ListNode(arr[i]);
        temp=temp->next;
    }
    return copy->next;
    }
};
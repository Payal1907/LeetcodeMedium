/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void store(Node* head, vector<Node*>& values)
    {
        if(!head) return;
        values.push_back(head);
        store(head->child,values);
        store(head->next,values);
    }
    Node* flatten(Node* head) {
        for(Node* h = head;h!=NULL;h=h->next){
            if(h->child){
                Node* temp1 = h->next;
                h->next=h->child;
                h->child->prev=h;
                h->child=NULL;
                Node* temp = h->next;
                while(temp->next){
                    temp=temp->next;
                }
                temp->next=temp1;
                if(temp1){
                    temp1->prev=temp;
                }
            }
        }
        // if(!head || (!head->next && !head->child)) return head;
        // vector<Node*> nodes;
        // store(head,nodes);
        // // Node* root = new Node(0);
        // for(int i=0;i<nodes.size()-1;i++){
        //     nodes[i]->next=nodes[i+1];
        //     nodes[i]->child=nullptr;
        // }
        // nodes.back()->next=nullptr;
        // nodes.back()->child=nullptr;
        // return nodes[0];
        return head;
    }
};
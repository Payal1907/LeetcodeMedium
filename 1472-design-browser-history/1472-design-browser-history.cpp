class BrowserHistory {
public:
    struct ListNode{
        string val;
        ListNode* next;
        ListNode* prev;
        ListNode() : val(""),next(nullptr),prev(nullptr){}
        ListNode(string s) : val(s),next(nullptr),prev(nullptr){}
        ListNode(string s, ListNode* next, ListNode* prev): val(s),next(next),prev(prev){}
    };
    ListNode* dummy = nullptr;
    BrowserHistory(string homepage) {
        ListNode* newNode = new ListNode(homepage);
        dummy=newNode;
    }
    
    void visit(string url) {
        ListNode* node = new ListNode(url);
        dummy->next=node;
        node->prev=dummy;
        dummy=dummy->next;    
    }
    
    string back(int steps) {
        while(dummy->prev && steps){
            dummy=dummy->prev;
            steps--;
        }
        return dummy->val;
    }
    
    string forward(int steps) {
        while(dummy->next && steps){
            dummy=dummy->next;
            steps--;
        }
        return dummy->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
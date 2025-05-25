class Solution {
public:
    vector<string> res;
    void backtrack(string curr,int n)
    {
        if(curr.length()==n)
        {
            res.push_back(curr);
            return;
        }
        backtrack(curr+'1',n);
        if(curr.empty()||curr.back()!='0') backtrack(curr+'0',n);
    }
    vector<string> validStrings(int n) {
    res.clear();
    backtrack("",n);
    return res;   
    }
};
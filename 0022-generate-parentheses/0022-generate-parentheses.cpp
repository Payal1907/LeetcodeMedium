class Solution {
public:
    vector<string> ans;
    void helper(string curr, int o, int c, int n){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }
        if(o<n) helper(curr+'(',o+1,c,n);
        if(c<o) helper(curr+')',o,c+1,n);
    }
    vector<string> generateParenthesis(int n) {
        helper("",0,0,n);
        return ans;

    }
};
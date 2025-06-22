class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    vector<string> ans;
    for(int i=0;i<s.size();i=i+k)
    {
        string small = "";
        for(int j=i;j<i+k;j++)
        {
            if(j<s.size()) small.push_back(s[j]);
            else small.push_back(fill);   
        }
        ans.push_back(small);
    }  
    
    return ans;  
    }
};
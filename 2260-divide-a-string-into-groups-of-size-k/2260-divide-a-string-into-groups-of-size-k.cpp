class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    vector<string> ans;
    string small="";
    for(int i=0;i<s.length();i++)
    {
        small+=s[i];
        if(small.size()==k)
        {
            ans.push_back(small);
            small="";
        }
    }
    if(small.length()!=0)
    {
        while(small.length()<k)
        {
            small+=fill;
        }
            ans.push_back(small);
    }
    
    return ans;
    }
};
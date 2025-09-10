class Solution {
public:
    string thousandSeparator(int n) {
    string s = to_string(n);
    int count = 0;
    string ans;
    for(int i=s.size()-1;i>=0;i--)
    {
        count++;
        ans.push_back(s[i]);
        if(count==3 && i!=0) 
        {
            ans.push_back('.');
            count=0;
        }
    }   
    reverse(ans.begin(),ans.end());
    return ans; 
    }
};
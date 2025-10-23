class Solution {
public:
    bool hasSameDigits(string s) {
    reverse(s.begin(),s.end());
    while(s.size()>2)
    {
        string newly="";
        for(int i=0;i<s.size()-1;i++)
        {
            int s0 = s[i]-'0';
            int s1 = s[i+1]-'0';
            newly.push_back((s0+s1)%10);
        }
        s=newly;
    }   
    return s[0]==s[1]; 
    }
};
class Solution {
public:
    string say(string s){
        string res = "";
        int count=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])//for initial characters, not storing freq, but freq for     consecutive same characters
            {
                count++;
            }
            else
            {
                res+=to_string(count)+s[i-1];
                count=1;
            }
        }
        res+=to_string(count)+s[s.size()-1];//for last character
        return res;
    }
    string countAndSay(int n) {
    if(n==1) return "1";
    else
    {
        return say(countAndSay(n-1));
    }   
    }
};
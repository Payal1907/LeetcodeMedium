class Solution {
public:
    string processStr(string s) {
     string res = "";
     int n = s.size();
     for(int i=0;i<n;i++){
        if(isalpha(s[i])) res+=s[i];
        else if(s[i]=='*' && !res.empty()) res.pop_back();
        else if(s[i]=='#') res+=res;
        else if(s[i]=='%') reverse(res.begin(),res.end());
     }  
     return res; 
    }
};
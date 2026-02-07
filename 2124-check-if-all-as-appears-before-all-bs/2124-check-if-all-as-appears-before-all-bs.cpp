class Solution {
public:
    bool checkString(string s) {
    int index_a=-1;
    int index_b=s.size();
     for(int i=0;i<s.size();i++)
     {
        if(s[i]=='a') index_a=i;
        if(s[i]=='b' && index_b==s.size()) index_b=i;
     } 
     return index_a<index_b;  
    }
};
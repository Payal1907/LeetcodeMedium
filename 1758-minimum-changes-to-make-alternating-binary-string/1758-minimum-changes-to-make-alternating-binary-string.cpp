class Solution {
public:
    int minOperations(string s) {
    int n = s.size();
    string s1,s2;
    for(int i=0;i<n-1;i+=2){
        s1+='1';
        s1+='0';
        s2+='0';
        s2+='1';
    } 
    if(s1.size()==n-1) s1+='1';
    if(s2.size()==n-1) s2+='0';
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s[i]) cnt1++;
    }
    int cnt2 = 0;
    for(int i=0;i<n;i++){
        if(s2[i]!=s[i]) cnt2++;
    } 
    return min(cnt1,cnt2);
    }
};
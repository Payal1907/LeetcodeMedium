class Solution {
public:
    int minOperations(string s) {
    int n = s.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt+=(s[i]^i)&1;
    }
    return min(cnt,n-cnt); 
    }
};
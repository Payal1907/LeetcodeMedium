class Solution {
public:
    // int minOps(string s){
    //     vector<int> ops(2,0);
    //     for(int i=0;i<s.size();i++){
    //         ops[(s[i]^i)&1]++;
    //     }
    //     return min(ops[0],ops[1]); 
    // }
    int minFlips(string s) {
        int n = s.size();
        vector<int> ops(2,0);
        for(int i=0;i<n;i++){
            ops[(s[i]^i)&1]++;
        }
        int ans = min(ops[0],ops[1]);
        for(int i=0;i<n-1;i++){
            ops[(s[i]^i)&1]--;
            ops[(s[i]^(n+i))&1]++;
            ans=min(ans,min(ops[0],ops[1]));
        }
        // int n = s.size();
        // string ss = s+s;
        // int ans = n;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,minOps(ss.substr(i,n)));
        // }
        return ans;  
    }
};
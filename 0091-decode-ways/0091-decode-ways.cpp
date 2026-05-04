class Solution {
public:
//ek hi character chose kro ya ek sath 2 character chose kro
//but 2 choose kr rhe ho to <=26 hona chaiye
//not start with 0
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0') return 0;
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int oneDigit = s[i-1]-'0';
            int twoDigit = stoi(s.substr(i-2,2));
            if(oneDigit!=0) dp[i]+=dp[i-1];
            if(twoDigit>=10 && twoDigit<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
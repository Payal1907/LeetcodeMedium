class Solution {
public:
    int climbStairs(int n) {
    int prev = 1;
    int prev2 = 1;
    int ans = 1;
    for(int i=2;i<=n;i++)
    {
        ans=prev+prev2;
        prev2=prev;
        prev=ans;
    } 
    return ans;  
    }
};
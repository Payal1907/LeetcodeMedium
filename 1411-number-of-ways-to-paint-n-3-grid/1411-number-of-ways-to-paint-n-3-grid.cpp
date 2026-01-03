class Solution {
public:
    int numOfWays(int n) {
      long long mod = 1e9+7;
      long long a = 6; //current = alternating
      long long b = 6; //current = all different
      for(int i=2;i<=n;i++){
        long long newa=(3*a+2*b)%mod; //next row - 3 alt, 2 diff
        long long newb=(2*a+2*b)%mod; //next row - 2 alt, 2 diff
        a=newa;
        b=newb;
      }
      return (a+b)%mod;
    }
};
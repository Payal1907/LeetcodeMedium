class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9+7;
    ll power(ll base, ll exp)
    {
        ll res =1;
        base=base%MOD;
        while(exp>0)
        {
            if(exp%2==1) res=(res*base)%MOD;
            base=(base*base)%MOD;
            exp=exp/2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
    return (power(5,(ll)((n+1)/2))*power(4,(ll)n/2))%MOD;
    }
};
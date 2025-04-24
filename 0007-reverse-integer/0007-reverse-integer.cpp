class Solution {
public:
    int reverse(int x) {
    long long n;
    n=x<0?-1LL*x:x;
    int rev=0;
    while(n>0)
    {
        int rem = n%10;
        if (rev>(INT_MAX-rem)/10) return 0;
        rev=rev*10+rem;
        n/=10;
    }  
    return x<0?-rev:rev;  
    }
};
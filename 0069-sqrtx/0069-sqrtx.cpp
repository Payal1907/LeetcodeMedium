class Solution {
public:
    int mySqrt(int x) {
    // for(int i=0;i<=x;i++)  
    // {
    //     if(i*i<=x && (i+1)*(i+1)>x) return i;
    // } 
    // return -1; can lead to overflow
    if(x==0||x==1) return x;
    int left = 1, right = x/2;
    int ans = 0;
    while(left<=right)
    {
        long long mid = left + (right-left)/2;
        long long sq = mid * mid;
        if(sq==x) return mid;
        if(sq<x)
        {
            ans = mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    return ans;
    }
};
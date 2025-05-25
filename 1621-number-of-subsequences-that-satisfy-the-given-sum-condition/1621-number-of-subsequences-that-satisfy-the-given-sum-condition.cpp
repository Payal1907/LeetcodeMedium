class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());  
    const int mod=1e9+7;
    int n=nums.size();
    vector<int> power(n, 1); 
    for (int i=1;i<n;i++) 
    {
        power[i]=(power[i - 1] * 2) % mod;
    }
    int l=0,r=n-1;
    long long res=0;
    while (l<=r) 
    {
        if(nums[l]+nums[r]<=target)
        {
            res=(res+power[r-l])%mod;
            l++;
        } 
        else 
        {
            r--;
        }
    }
    return (int)res;
    }
};
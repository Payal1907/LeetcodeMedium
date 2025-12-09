class Solution {
public:
    int specialTriplets(vector<int>& nums) {
    long long count = 0;
    const long long mod = 1e9+7;
    int n = nums.size();
    unordered_map<long long,long long> mpr,mpl;
    for(auto num : nums) mpr[num]++;
    for(int i=0;i<n;i++)
    {
        int curr = nums[i];
        long long target = nums[i]*2;
        mpr[curr]--;
        count=(count+(mpl[target]*mpr[target])%mod)%mod;
        mpl[nums[i]]++;
    }  
    return (int)count;  
    }
};
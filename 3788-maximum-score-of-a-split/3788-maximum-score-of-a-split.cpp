class Solution {
public:
    long long maximumScore(vector<int>& nums) {
    long long mxs = LLONG_MIN;
    int n = nums.size();
    vector<long long> prefix(n);
    prefix[0]=nums[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
    }
    vector<int> suffixMin(n,INT_MAX);
    suffixMin[n-1]=INT_MAX;
    for(int i=n-2;i>=0;i--){
        suffixMin[i]=min(nums[i+1],suffixMin[i+1]);
    }
    for(int i=0;i<n-1;i++){
        long long pre = prefix[i];
        long long suf = (suffixMin[i]==INT_MAX?0:suffixMin[i]);
        mxs=max(mxs,pre-suf);
    }
    return mxs;
    }
};
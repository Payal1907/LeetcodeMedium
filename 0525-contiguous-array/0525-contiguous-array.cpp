class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> mp;
    int mx = 0;
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum+=(nums[i]==0?-1:1);
        if(sum==0) mx=i+1;
        else if(mp.find(sum)!=mp.end()) mx=max(mx,i-mp[sum]);
        else mp[sum]=i; //pehli pehli baar
    }  
    return mx;
    }
};
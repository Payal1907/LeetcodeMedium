class Solution {
public:
    int reverseNumber(int n){
        int num = 0;
        while(n){
            num=num*10+n%10;
            n=n/10;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long long reversed = reverseNumber(nums[i]);
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[reversed]=i;
        }
        return ans==INT_MAX?-1:ans;   
    }
};
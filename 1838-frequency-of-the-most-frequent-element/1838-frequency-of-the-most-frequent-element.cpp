class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        int ans = 1;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while((long long)nums[r]*(r-l+1)-sum>k){
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
        }
        // vector<int> prefix(n,0);
        // prefix[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]+nums[i];
        // }
        // // prefix[n]=prefix[n-1]+nums[n-1];
        // for(auto pre : prefix) cout<<pre<<" ";
        // for(int i=n-1;i>=0;i--){
        //     int expected = nums[i]*(i+1);
        //     int sum = prefix[i];
        //     // for(int j=i;j>=0;j--){
        //     //     sum+=nums[j];
        //     // }
        //     if(expected-sum<=k) return i+1;
        // } 
        return ans;
    }
};
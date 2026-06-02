class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    int n =nums.size();
    int mx = *max_element(nums.begin(),nums.end());
    int i=0,j=0;
    long long ans = 0;
    int cnt = 0;
    while(i<n){
        if(nums[i]==mx) cnt++;
        while(cnt>=k){
            ans+=n-i;
            if(nums[j]==mx){
                cnt--;
            }
            j++;
        }
        i++;
    }   
    return ans; 
    }
};
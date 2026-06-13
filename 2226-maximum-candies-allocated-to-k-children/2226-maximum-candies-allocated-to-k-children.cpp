class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(),nums.end());
        int res = 0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long children = 0;
            for(int pile : nums){
                children+=pile/mid;
            }
            if(children>=k){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return res;
    }
};
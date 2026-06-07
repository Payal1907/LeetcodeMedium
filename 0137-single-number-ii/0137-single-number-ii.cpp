class Solution {
public:
//brute me tu hashmap use krke kr skti hai, lekin TC to linear hogi and SC would also be constant
//but lets try bitwise 
    int sortedMethod(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i+=3){
            if(nums[i]!=nums[i+1]) return nums[i];
        }
        return nums[n-1];
    }
    int singleNumber(vector<int>& nums) {
        return sortedMethod(nums);
    int ans =0;
    for(int bitIndex = 0; bitIndex<32; bitIndex++)
    {
        int cnt = 0;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i]&(1<<bitIndex)) cnt++;
        }
        if(cnt%3==1) ans=ans|(1<<bitIndex); 
    }
    return ans;
    }
};
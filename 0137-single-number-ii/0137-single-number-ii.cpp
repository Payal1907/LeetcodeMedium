class Solution {
public:
//brute me tu hashmap use krke kr skti hai, lekin TC to linear hogi and SC would also be constant
//but lets try bitwise 
    int singleNumber(vector<int>& nums) {
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
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> ans;
    int val = 0;
    for(auto num : nums)
    {
        val=((val<<1)+num)%5;
        //value ko ek place left shift kr rhi hai usme num add kr rhi hai
        //uska binary form bnaane ke liye
        ans.push_back(val==0);
    } 
    return ans;  
    }
};
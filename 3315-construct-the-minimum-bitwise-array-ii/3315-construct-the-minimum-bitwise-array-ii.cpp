class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(auto num : nums){
            if(num&1){
                auto mn = ((num + 1) & ~num) >> 1;
                ans.push_back(num & ~mn);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
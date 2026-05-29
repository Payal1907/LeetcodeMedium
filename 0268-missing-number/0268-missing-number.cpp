class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto num : nums) sum+=num;
        return (int)n*(n+1)/2 - sum;
        
    }
};
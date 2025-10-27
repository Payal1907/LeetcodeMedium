class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> twoSum;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (twoSum.find(complement) != twoSum.end()) {
            return {twoSum[complement], i};
        }
        twoSum[nums[i]] = i;
    }
    return {};

    }
};
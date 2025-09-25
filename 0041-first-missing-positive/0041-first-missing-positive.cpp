class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for (auto num : nums)
            s.insert(num);
        for (int num = 1; num <= 100001; num++) {
            if (s.find(num) == s.end())
                return num;
        }
        return 0;
    }
};
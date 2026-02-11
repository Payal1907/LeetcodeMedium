class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> odd;
            unordered_set<int> even;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);
                if (odd.size() == even.size())
                    mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};
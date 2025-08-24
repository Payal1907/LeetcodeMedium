class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prevOnes = 0;
        int currOnes = 0;
        int ans = 0;
        bool zero = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currOnes++;
                ans = max(ans, prevOnes + currOnes);
            } else {
                zero = true;
                prevOnes = currOnes;
                currOnes = 0;
            }
        }
        if (!zero) {
            return ans - 1;
        }
        return ans;
    }
};

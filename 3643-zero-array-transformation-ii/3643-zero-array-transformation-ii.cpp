class Solution {
public:
    bool isValid(int mid, const vector<int>& nums, const vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < mid; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];
            diff[start] -= val;
            diff[end + 1] += val;
        }
        int curr = 0; 
            for (int i = 0; i < n; i++) {
                curr += diff[i];
                if (nums[i] + curr > 0) return false;
            }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        bool allZeroOrLess = true;
        for (auto num : nums) {
            if (num > 0) {
                allZeroOrLess = false;
                break;
            }
        }
        if (allZeroOrLess) return 0;
        int low = 1, high = queries.size(), ans = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(isValid(mid,nums,queries))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
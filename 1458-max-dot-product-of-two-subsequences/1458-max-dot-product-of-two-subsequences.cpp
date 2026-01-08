class Solution {
public:
    vector<vector<int>> tt;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if(i>=nums1.size() || j>=nums2.size()) return -1e9;
        if(tt[i][j]!=-1) return tt[i][j];
        int ans = INT_MIN;
        ans = max(ans,nums1[i]*nums2[j]+max(0,solve(i+1,j+1,nums1,nums2)));
        ans = max(ans, solve(i+1,j,nums1,nums2));
        ans = max(ans,solve(i,j+1,nums1,nums2));
        return tt[i][j]=ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        tt.assign(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(0,0,nums1,nums2);
    }
};
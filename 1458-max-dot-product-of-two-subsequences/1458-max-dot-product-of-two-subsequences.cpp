class Solution {
public:
    // vector<vector<int>> tt;
    // int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
    //     if(i>=nums1.size() || j>=nums2.size()) return -1e9;
    //     if(tt[i][j]!=-1) return tt[i][j];
    //     int ans = INT_MIN;
    //     ans = max(ans,nums1[i]*nums2[j]+max(0,solve(i+1,j+1,nums1,nums2)));
    //     ans = max(ans, solve(i+1,j,nums1,nums2));
    //     ans = max(ans,solve(i,j+1,nums1,nums2));
    //     return tt[i][j]=ans;
    // }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> tt;
        tt.assign(n+1, vector<int>(m+1, -1e9));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int take = nums1[i]*nums2[j]+max(0,tt[i+1][j+1]);
                int skip1 = tt[i+1][j];
                int skip2 = tt[i][j+1];
                tt[i][j]=max({take,skip1,skip2});
            }
        }
        // return solve(0,0,nums1,nums2);
        return tt[0][0];
    }
};
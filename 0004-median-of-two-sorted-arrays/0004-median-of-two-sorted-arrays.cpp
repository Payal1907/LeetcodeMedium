class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i=0, j=0;
        int n = nums1.size(), m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i++]);
            }
            else ans.push_back(nums2[j++]);
        }
        while(i<nums1.size()) ans.push_back(nums1[i++]);
        while(j<nums2.size()) ans.push_back(nums2[j++]);
        int k = ans.size();
        if(k%2) return ans[k/2];
        return (ans[k/2]+ans[k/2-1])/2.0;
    }
};
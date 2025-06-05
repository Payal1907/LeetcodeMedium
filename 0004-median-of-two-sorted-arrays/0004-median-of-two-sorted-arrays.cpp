class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i=0,j=0,k=0;
    int m = nums1.size(), n = nums2.size();
    int size = m+n;
    vector<int> merged(size);
    while(i<m && j<n)  
    {
        if(nums1[i]<nums2[j]) merged[k++]=nums1[i++];
        else merged[k++]=nums2[j++];
    }
    while(i<m) 
    {
        merged[k++]=nums1[i++];
    }  
    while(j<n)
    {
        merged[k++]=nums2[j++];
    }
    if(size%2==1) return (double)merged[size/2];
    double median = ((double)merged[size/2] + (double)merged[(size/2)-1])/2.0; 
    return median;
    }
};
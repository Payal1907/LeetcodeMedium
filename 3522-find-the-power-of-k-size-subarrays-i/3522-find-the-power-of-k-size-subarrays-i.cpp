class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res(n-k+1,-1);
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(j && nums[j]-nums[j-1]!=1) i = j;
        if(j-i+1==k) res[i++]=nums[j];
    }  
    return res; 
    }
};
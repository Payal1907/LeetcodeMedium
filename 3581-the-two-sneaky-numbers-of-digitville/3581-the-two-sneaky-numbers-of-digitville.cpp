class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
    int n = nums.size();
    bool zero = false;
    vector<int> ans;
    for(int i=0;i<n;i++) nums[i]+=1;
    for(int i=0;i<n;i++)
    {
        int index=abs(nums[i])-1;
        if(nums[index]<0) ans.push_back(index);
        else nums[index]*=-1;
    }
    return ans;
    }
};
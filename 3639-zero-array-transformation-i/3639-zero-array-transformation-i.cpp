class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> totalEffect(n+1,0);
        for(int i=0;i<queries.size();i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            totalEffect[start]--;
            totalEffect[end+1]++;
        }  
        vector<int> res(n);
        res[0]=totalEffect[0];
        for(int i=1;i<n;i++)
        {
            res[i]=res[i-1]+totalEffect[i];
        } 
        for(int i=0;i<n;i++)
        {
            if(nums[i]+res[i]>0) return false;
        } 
        return true;
    }
};
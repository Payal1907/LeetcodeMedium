class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                long long trg = (long long)target-(long long)nums[i]-(long long)nums[j];
                int l = j+1, h=n-1;
                while(l<h)
                {
                    if(nums[l]+nums[h]<trg) l++;
                    else if(nums[l]+nums[h]>trg) h--;
                    else 
                    {
                        st.insert({nums[i],nums[j],nums[l],nums[h]});
                        l++;
                        h--;
                    }
                }
            }
        }  
        for(auto it : st)
        {
            ans.push_back(it);
        }  
        return ans;
    }
};
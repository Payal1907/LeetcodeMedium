class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int maxi=0;
        bool all_neg = 1;
        for(auto num : nums)
        {
            st.insert(num);
            if(num>=0) all_neg=0;
        }
        if(all_neg) return *max_element(nums.begin(),nums.end());
        for(auto num : st)
        {
            if(num<0) continue;
            maxi+=num;
        } 
        return maxi;   
    }
};
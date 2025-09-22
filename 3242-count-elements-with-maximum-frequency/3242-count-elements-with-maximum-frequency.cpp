class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    int total = 0;
    unordered_map<int,int> mp;
    for(auto num : nums)
    {
        mp[num]++;
    } 
    int maxi = INT_MIN;
    for(auto p : mp)
    {
        if(p.second>maxi) maxi=p.second;
    }
    for(auto p : mp)
    {
        if(p.second==maxi) total+=p.second;
    } 
    return total; 
    }
};
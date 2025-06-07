class Solution {
public:
//brute me tu hashmap use krke kr skti hai, lekin TC to linear hogi and SC would also be constant
//but lets try bitwise 
    int singleNumber(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(auto num : nums)
    {
        mp[num]++;
    }  
    for(auto pair : mp)
    {
        if(pair.second==1) return pair.first;
    }
    return 0;
    }
};
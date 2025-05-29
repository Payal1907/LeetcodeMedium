class Solution {
public:
    int findLucky(vector<int>& arr) {
    int maxi = -1;
    unordered_map<int,int> mp;
    for(auto num : arr)
    {
        mp[num]++;
    }
    for(auto pair : mp)
    {
        if(pair.first==pair.second && pair.first>maxi)
        {
            maxi=pair.first;
        }
    }
    return maxi;  
    }
};
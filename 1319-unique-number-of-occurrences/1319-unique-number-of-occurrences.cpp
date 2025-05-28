class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> mp;
    unordered_set<int> s;
    for(auto num : arr)
    {
        mp[num]++;
    }
    for(auto freq : mp)
    {
        s.insert(freq.second);
    }
    return mp.size()==s.size();
    }
};
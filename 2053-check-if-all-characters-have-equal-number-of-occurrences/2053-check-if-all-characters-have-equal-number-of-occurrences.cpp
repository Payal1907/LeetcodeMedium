class Solution {
public:
    bool areOccurrencesEqual(string s) {
    unordered_map<char,int> mp;
    for(auto ch : s)
    {
        mp[ch]++;
    }
    int f = mp[s[0]]; 
    for(auto pair : mp)
    {
        if(pair.second!=f) return false;
    } 
    return true;  
    }
};
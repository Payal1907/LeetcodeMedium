class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<=1) return false;
        unordered_map<int,int> mp;
        for(auto card : deck)
        {
            mp[card]++;
        }
        int g=0;
        for(auto p : mp)
        {
            g=__gcd(g,p.second);
        }
        return g>=2;  
    }
};
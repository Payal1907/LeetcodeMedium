class Solution {
public:
    int longestSubstring(string s, int k) {
    int n = s.size();
    int res = 0;
    vector<int> count(26,0);
    for(auto ch : s) count[ch -'a']++;
    for(int i=0;i<n;i++)
    {
        if(count[s[i]-'a']<k) //jaise hi koi invalid element aya
        //we check on either left or right
        {
            int l = longestSubstring(s.substr(0,i),k);
            int r = longestSubstring(s.substr(i+1),k);
            return max(l,r);
        }
    }
    return s.size();
    }
};
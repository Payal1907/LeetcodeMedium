class Solution {
public:
    bool isValid(int k, vector<int>& count)
    {
        int distinct = 0;
        int atleastK = 0;
        for(int ch=0;ch<26;ch++)
        {
            if(count[ch]>0) distinct++;
            if(count[ch]>=k) atleastK++;
        }
        return distinct==atleastK;
    }
    int longestSubstring(string s, int k) {
    int n = s.size();
    if(n==0||k>n) return 0;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        vector<int> count(26,0);
        for(int j=i;j<n;j++)
        {
            count[s[j]-'a']++;
            if(isValid(k,count)) res=max(res,j-i+1);
        }
    }
    return res;
    }
};
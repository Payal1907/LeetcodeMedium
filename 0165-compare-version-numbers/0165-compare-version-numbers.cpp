class Solution {
public:
    vector<string> makeTokens(string version,int s)
    {
        vector<string> tokens;
        int start = 0;
        for(int i=0;i<version.size();i++)
        {
            if(version[i]=='.')
            {
                if(i>start) tokens.push_back(version.substr(start,i-start));
                start=i+1;
            }
        }
        if(start<version.size()) tokens.push_back(version.substr(start));
        while((int)tokens.size()<s) tokens.push_back("0");
        return tokens;

    }
    int compareVersion(string version1, string version2) {
    int m = version1.size();
    int n = version2.size();
    int s = m>=n?m:n;
    vector<string> token1=makeTokens(version1,s);
    vector<string> token2=makeTokens(version2,s);
    for(int i=0;i<s;i++)
    {
        if(stoi(token1[i])>stoi(token2[i])) return 1;
        else if(stoi(token1[i])<stoi(token2[i])) return -1;
    }  
    return 0;
    }
};
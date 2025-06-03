class Solution {
public:
    string convert(string s, int numRows) {
    if(numRows==1) return s;
    vector<vector<char>> zigzag(numRows);
    int i=0,n=s.size();
    string ans = "";
    while(i<n)
    {
        for(int goDown = 0;goDown<numRows && i<n;goDown++)
        {
            zigzag[goDown].push_back(s[i++]);
        }
        for(int goUp = numRows-2;goUp>0 && i<n;goUp--)
        {
            zigzag[goUp].push_back(s[i++]);
        }
    }
    for(int j=0;j<numRows;j++)
    {
        for(char c : zigzag[j])
        {
            ans+=c;
        }
    }
    return ans;
    }
};
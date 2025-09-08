class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
    if(n==2) return {1,1};
    for(int i=1;i<=n;i++)
    {
        if(to_string(i).find('0')==std::string::npos && to_string(n-i).find('0')==std::string::npos) return {i,n-i};
    }   
    return {};
    }
};
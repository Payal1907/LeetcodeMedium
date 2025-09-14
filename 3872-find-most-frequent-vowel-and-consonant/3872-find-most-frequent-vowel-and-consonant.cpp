class Solution {
public:
    int maxFreqSum(string s) {
    unordered_map<char,int> mp;
    for(auto c : s)
    {
        mp[c]++;
    } 
    int f_v = 0;
    int f_c = 0;
    for(auto pair : mp)
    {
        int a = pair.first;
        int b = pair.second;
        if((a=='a'||a=='e'||a=='i'||a=='o'||a=='u') && b>f_v) f_v=b;
        else if(b>f_c && (a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u')) f_c=b; 
    } 
    return f_v+f_c; 
     
    }
};
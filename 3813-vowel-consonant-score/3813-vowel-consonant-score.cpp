class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        unordered_set<char> st = {'a','e','i','o','u'};
        for(int i=0;i<s.size();i++){
            if(s[i]<97 || s[i]>122) continue;
            else if(st.count(s[i])) v++;
            else c++;
        }
        return (c>0)?std::floor(v/c):0;
    }
};
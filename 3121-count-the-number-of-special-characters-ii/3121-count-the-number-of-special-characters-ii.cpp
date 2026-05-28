class Solution {
public:
    int numberOfSpecialChars(string s) {
    int n = s.size();
    unordered_map<char,int> mp;
    unordered_set<int> st;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(islower(s[i])) mp[s[i]]=i; 
    }  
    for(int i=0;i<n;i++){
        if(isupper(s[i]) && mp.count(tolower(s[i])) && mp[tolower(s[i])]<i && !st.count(s[i])){
            cnt++;
        } 
        st.insert(s[i]);
    }
    return cnt;
    }
};
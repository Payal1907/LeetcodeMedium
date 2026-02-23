class Solution {
public:
    bool hasAllCodes(string s, int k) {
    set<string> st;
    if(s.size()<k) return false;
    for(int i=0;i<=s.size()-k;i++){
        string code = s.substr(i,k);
        st.insert(code);
    }   
    for(auto code : st) cout<<code<<endl;
    int total = (int)pow(2,k);
    return total==st.size(); 
    }
};
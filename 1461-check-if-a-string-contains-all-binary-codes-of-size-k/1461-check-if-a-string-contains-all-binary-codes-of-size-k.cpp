class Solution {
public:
    bool hasAllCodes(string s, int k) {
    unordered_set<string> st;
    //set uses red-black, increases the complexity
    //so use unordered set
    if(s.size()<k) return false;
    for(int i=0;i<=s.size()-k;i++){
        string code = s.substr(i,k);
        st.insert(code);
    }   
    int total = (int)pow(2,k);
    return total==st.size(); 
    }
};
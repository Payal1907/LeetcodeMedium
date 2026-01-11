class Solution {
public:
    int residuePrefixes(string s) {
        int count = 0;
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
            if(st.size()==(i+1)%3) count++;
        }
        return count;
    }
};
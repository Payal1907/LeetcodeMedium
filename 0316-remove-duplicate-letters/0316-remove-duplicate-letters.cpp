class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_set<char> seen;
        unordered_map<char,int> lastocc;
        string res = "";
        for(int i=0;i<s.size();i++){
            lastocc[s[i]]=i;
        } 
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(seen.find(c)!=seen.end()) continue;
            while(!st.empty() && c<st.top() && i<lastocc[st.top()]){
                    seen.erase(st.top());
                    st.pop();
            }
            seen.insert(c);
            st.push(c);
        }  
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }

        return res;
    }
};
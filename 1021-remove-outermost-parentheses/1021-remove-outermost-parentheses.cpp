class Solution {
public:
    string removeOuterParentheses(string s) {
    stack<char> st;
    string removed;
    for (int i = 0; i < s.size(); i++) 
    {
        if (s[i] == '(') 
        {
            if (!st.empty()) 
            {
                removed.push_back(s[i]);
            }
            st.push(s[i]);
        } 
        else 
        {
            st.pop();
            if (!st.empty()) 
            {
                removed.push_back(s[i]);
            }
        }
    }

    return removed;
    }
};
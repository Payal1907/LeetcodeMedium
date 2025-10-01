class Solution {
public:
//basic funda hai ki smaller number bnaane ke liye increasing order me koshish kr 
//numbers ko rkhne ke liye
//notes bna lena iske
    string removeKdigits(string num, int k) {
        stack<char> st;
        string res="";
        for(char c : num)
        {
            while(!st.empty() && k>0 && st.top()>c)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }  
        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size() && res[i]=='0') i++;
        res=res.substr(i);
        return res.empty()?"0":res;
    }
};
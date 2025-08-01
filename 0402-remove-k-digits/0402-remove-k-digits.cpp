class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
        string res="";
        for(char digit : num)
        {
            while(!stack.empty() && k>0 && stack.back()>digit)
            {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }  
        while(k>0)
        {
            stack.pop_back();
            k--;
        }
        bool leadingZero=true;
        for(auto digit : stack)
        {
            if(leadingZero && digit=='0') continue;
            leadingZero=false;
            res+=digit;
        }
        return res.empty()?"0":res;
    }
};
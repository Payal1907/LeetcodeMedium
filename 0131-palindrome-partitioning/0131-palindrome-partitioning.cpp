class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void func(int index, string& s, vector<string>& substring,vector<vector<string>>& ans)
    {
        if(index==s.size())
        {
            ans.push_back(substring);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                substring.push_back(s.substr(index,i-index+1));
                func(i+1,s,substring,ans);
                substring.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substring;
        func(0,s,substring,ans);
        return ans;    
    }
};
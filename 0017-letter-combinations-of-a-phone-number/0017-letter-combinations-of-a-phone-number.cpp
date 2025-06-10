class Solution {
public:
    void backtrack(string& digits,int index, string& curr,vector<string>& ans,vector<string> mapping)
    {
        if(index==digits.length())
        {
            ans.push_back(curr);
            return;
        }
        string letters = mapping[digits[index]-'0'];
        for(char ch : letters)
        {
            curr.push_back(ch);
            backtrack(digits,index+1,curr,ans,mapping);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
    vector<string> ans;
    vector<string> mapping = 
    {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    string curr;
    backtrack(digits,0,curr,ans,mapping);
    return ans;
    }
};
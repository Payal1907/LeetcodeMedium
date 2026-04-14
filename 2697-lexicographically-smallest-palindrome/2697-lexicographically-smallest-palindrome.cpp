class Solution {
public:
    string makeSmallestPalindrome(string s) {
    int i = 0, j = s.size()-1;
    string ans = s;
    while(i<j){
        if(s[i]!=s[j]){
            char ch = min(s[i],s[j]);
            ans[i]=ans[j]=ch;
        }
        i++;
        j--;
    }   
    return ans; 
    }
};
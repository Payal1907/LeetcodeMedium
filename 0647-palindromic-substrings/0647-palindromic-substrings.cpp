class Solution {
public:
    bool isPalindrome(string s){
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
    int ans = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        string ss = "";
        for(int j=i;j<n;j++){
            ss+=s[j];
            if(isPalindrome(ss)) ans++;
        }
    }
    return ans;    
    }
};
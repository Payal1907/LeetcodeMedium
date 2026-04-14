class Solution {
public:
    int countPalindrome(string s, int l, int r){
        int cnt = 0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
    int ans = 0;
    int n = s.size();
    for(int i=0;i<n;i++){                          
        ans+=countPalindrome(s,i,i);
        // while(l>=0 && r<n && s[l]==s[r]){ //consider every index as centre, find odd length palindrome
        //     ans++;
        //     l--;
        //     r++;
        // }
        ans+=countPalindrome(s,i,i+1);
        // l=i,r=i+1;
        // while(l>=0 && r<n && s[l]==s[r]){ //even length palindrome
        //     ans++;
        //     l--;
        //     r++;
        // }
    }  
    return ans;  
    }
};
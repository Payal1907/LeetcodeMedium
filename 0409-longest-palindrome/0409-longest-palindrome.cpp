class Solution {
public:
    int longestPalindrome(string s) {
     unordered_map<char,int> mp;
     for(auto ch : s){
        mp[ch]++;
     } 
     int count = 0;
     for(auto p : mp){
        if(p.second%2==0){
            count+=p.second;
        }
        else{ //similars in odd count "ccc"
        count+=p.second-1;
        }
     }
     return (count<s.size() && count%2==0)?count+1:count;
    }
};
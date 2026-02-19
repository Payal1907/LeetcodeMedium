class Solution {
public:
    int countBinarySubstrings(string s) {
    int count = 1;
    int ans = 0;
    int prev = 0;
    for(int i=1;i<s.size();i++){
          if(s[i]==s[i-1]){
            count++;
          }
          else{
            prev=count;
            count=1;
          }
          if(count<=prev) ans++;
    } 
    return ans;
    }
};
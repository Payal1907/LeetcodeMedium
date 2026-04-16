class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    vector<int> f(26,0);
    for(auto ch : magazine){
        f[ch-'a']++;
    }
    for(auto ch : ransomNote){
        if(f[ch-'a']==0) return false;
        f[ch-'a']--;
    }
    return true;
    }
};
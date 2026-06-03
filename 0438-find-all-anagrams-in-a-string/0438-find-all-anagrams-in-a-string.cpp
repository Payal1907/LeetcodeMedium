class Solution {
public:
    vector<int> findAna(string& s, string& p){
        vector<int> res;
        if(s.size()<p.size()) return res;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0;i<p.size();i++){
            v1[p[i]-'a']++;
            v2[s[i]-'a']++;
        }
        if(v1==v2) res.push_back(0);
        for(int i=p.size();i<s.size();i++){
            v2[s[i]-'a']++;
            v2[s[i-p.size()]-'a']--;
            if(v1==v2) res.push_back(i-p.size()+1);
        }
        return res;
    }
    vector<int> findAnagrams(string s, string p) {
    return findAna(s,p);
    }
};
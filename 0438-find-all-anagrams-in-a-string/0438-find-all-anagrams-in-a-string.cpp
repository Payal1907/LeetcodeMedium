class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if(s.size()<p.size()) return result;
    vector<int> pFreq(26,0);
    vector<int> sFreq(26,0);
    for(int i=0;i<p.size();i++)
    {
        pFreq[p[i]-'a']++; //basically giving every alphabet an index to store its frequency
        sFreq[s[i]-'a']++;
    }   
    if(pFreq==sFreq) result.push_back(0);
    //ab aage ke window check krenge p.size() index se
    for(int i=p.size();i<s.size();i++)
    {
        sFreq[s[i]-'a']++; //new character freq added
        sFreq[s[i-p.size()]-'a']--; //old character freq removed, basically reducing the size of window to p size
        if(sFreq==pFreq) result.push_back(i-p.size()+1);
    } 
    return result;
    }
};
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
    unordered_map<string,int> mp;
    for(auto& word : words){
       if(word.length()>=k) mp[word.substr(0,k)]++;
       //agr usse choti hogi to isliye pehle check kr
    }
    int cnt = 0;
    for(auto& p : mp){
        if(p.second>=2) cnt++;
    }
    return cnt; 
    }
};
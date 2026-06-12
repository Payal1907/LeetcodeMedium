class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;
    int n = strs.size();
    for(int i=0;i<n;i++){
       string original = strs[i];
       sort(strs[i].begin(),strs[i].end());
       mp[strs[i]].push_back(original);
    }
    for(auto p : mp){
        auto str  = p.first;
        auto s = p.second;
        ans.push_back(s);
    }
    return ans;
    }
};
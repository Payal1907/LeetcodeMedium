class Solution {
public:
    string getHint(string secret, string guess) {
    int bulls = 0;
    vector<int> common;
    unordered_map<char,int> mp;
    int n = secret.size();
    for(int i=0;i<n;i++){
        if(secret[i]==guess[i]) bulls++;
        mp[secret[i]]++;
    }  
    for(auto num : guess){
        if(mp.count(num)) {
            common.push_back(num);
            mp[num]--;
            if(mp[num]==0) mp.erase(num);
        }
    }
    return to_string(bulls) + "A" + to_string(common.size()-bulls) + "B";
    }
};
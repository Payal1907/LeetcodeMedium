class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    //basic insertion into a set, so that we can find the count of most spoken language easily
    vector<unordered_set<int>> know(languages.size());
    for(int i=0;i<languages.size();i++)
    {
        for(int lang : languages[i])
        {
            know[i].insert(lang);
        }
    }
    unordered_set<int> candidates;
    for(auto& f : friendships)
    {
        int u1 = f[0]-1, u2=f[1]-1;
        bool can=false;
        for(auto lang : know[u1])
        {
            if(know[u2].count(lang)) 
            {
                can=true;
                break;
            }
        }
        if(!can)
        {
            candidates.insert(u1);
            candidates.insert(u2);
        }
    }
    if(candidates.empty()) return 0;
    unordered_map<int,int> mp;
    for(auto num : candidates)
    {
        for(int lang : know[num])
        {
            mp[lang]++;
        }
    }
    int maxi = -1;
    for(auto p : mp)
    {
        maxi=max(maxi,p.second);
    }
    return (int)candidates.size()-maxi;

    }
};
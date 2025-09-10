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
    //ek tune candidates ka set bnaaya hai, ab hm check krnege ki frienships array me kon konse
    //elements friends bn sakte hai, aur jo nai ban skte unko store krnege
    unordered_set<int> candidates;
    for(auto& f : friendships)
    {
        int u1 = f[0]-1, u2=f[1]-1;
        bool can=false;
        for(auto lang : know[u1])
        {
            //isme bs dhoondh rhe hai ki dono me atleast ek elements intersect ho jaaye
            if(know[u2].count(lang)) 
            {
                can=true;
                break;
            }
        }
        //ab jo users frienship nai kr skte unka naam store kr liya hai
        if(!can)
        {
            candidates.insert(u1);
            candidates.insert(u2);
        }
    }
    if(candidates.empty()) return 0;
    //finding most spoken language
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
    //ab jo friends nai bn skte total unme se konsa aise langugage hai wo most spoken hai, taaki
    //hme minimum logo ko ye sikhana pde
    return (int)candidates.size()-maxi;

    }
};
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,deque<int>> mp;
        int mn = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()>3) mp[nums[i]].pop_front();
            if(mp[nums[i]].size()==3){
                int dist = 2*(mp[nums[i]][2]-mp[nums[i]][0]);
                mn=min(mn,dist);
            }
        }
        // unordered_map<int,vector<int>> mp;
        // int mn = INT_MAX;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     mp[nums[i]].push_back(i);
        // }
        // for(auto p : mp){
        //     vector<int>& v = p.second;
        //     if(v.size()<3) continue;
        //     for(int i=2;i<v.size();i++){ //(j - i) + (k - j) + (k - i)
        //         int dist = 2*(v[i]-v[i-2]);
        //         mn=min(mn,dist);
        //     }
        // }
        return mn==INT_MAX?-1:mn;
    }
};
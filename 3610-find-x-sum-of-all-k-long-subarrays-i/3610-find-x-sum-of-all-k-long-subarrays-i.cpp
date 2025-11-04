class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int j=0;j<k;j++) mp[nums[j]]++;
    ans.push_back(calculateXSum(mp,x));
    for(int i=1;i<=n-k;i++)
    {
        mp[nums[i-1]]--; //slinding the window
        if(mp[nums[i-1]]==0) mp.erase(nums[i-1]); //0 hogya to remove krde
        mp[nums[i+k-1]]++; //next element add kr
        ans.push_back(calculateXSum(mp,x)); //for new added element
    }    
    return ans;
    }
    int calculateXSum(const unordered_map<int,int>& mp,int x)
    {
        priority_queue<pair<int,int>> pq;
        for(const auto& ele : mp)
        {
            pq.push({ele.second,ele.first});
        }
        int sum = 0;
        for(int i=0;i<x &&!pq.empty();i++) //agr x se less elements hue to
        {
            auto top = pq.top();
            pq.pop();
            sum+=top.first*top.second;
        }
        return sum;

    }
};
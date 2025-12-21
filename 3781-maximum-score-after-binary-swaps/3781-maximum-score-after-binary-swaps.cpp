class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
    long long n = nums.size(), ans=0,i=0;
    priority_queue<long long> pq;
    while(i<n)
    {
        pq.push(nums[i]);
        if(s[i]=='1')
        {
            ans+=pq.top();
            pq.pop();
        }
        //jitne 1 hai utne numbers hi add honge, aur wo max honge to bs
        i++;
    }
    return ans;
    }
};
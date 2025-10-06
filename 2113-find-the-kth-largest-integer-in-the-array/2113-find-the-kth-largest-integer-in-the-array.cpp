class Solution {
public:
    struct Compare{
    bool operator()(const string& a, const string& b)
    {
        if(a.size()==b.size()) return a>b;
        return a.size()>b.size();
    }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,Compare> pq;
        for(auto num : nums)
        {
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
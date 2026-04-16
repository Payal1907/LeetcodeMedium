class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int n = nums.size();
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        pq.push({nums[i],i});
        while(!pq.empty()&& pq.top().second<=i-k){
            //window bnne ke baad hi next element dala jb check kiya ki top wale ka index agr chota
            //hai window size se tb tk remove kiya
            pq.pop();
        }
        if(i>=k-1){ //jaise hi window bna hoga
            ans.push_back(pq.top().first);
        }
    }
    return ans;
    }
};
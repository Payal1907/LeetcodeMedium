class Solution {
public:
    int minimumCost(vector<int>& nums) {
    int sum = 0,cnt=0;
    int n =nums.size();
    sort(nums.begin(),nums.end());
    for(int i=n-1;i>=0;i--){
        cnt++;
        if(cnt%3==0) continue;
        sum+=nums[i];
    }
    return sum;
    }
};
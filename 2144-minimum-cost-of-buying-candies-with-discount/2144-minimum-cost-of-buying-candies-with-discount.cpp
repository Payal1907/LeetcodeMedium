class Solution {
public:
    int minimumCost(vector<int>& nums) {
    int sum = 0;
    int n =nums.size();
    int i;
    sort(nums.begin(),nums.end());
    for(i=n-1;i>=2;i-=3){
        sum+=(nums[i]+nums[i-1]);
    } 
    while(i>=0){sum+=nums[i--];} 
    return sum; 
    }
};
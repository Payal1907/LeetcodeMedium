class Solution {
public:
    int dominantIndices(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        int sum = 0;
        for(int j=i+1;j<n;j++){
            sum+=nums[j];
        }
        if(sum/(n-(i+1))<nums[i]) count++;
    }   
    return count;
    }
};
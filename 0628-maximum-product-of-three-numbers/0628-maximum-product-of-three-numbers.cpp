class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    if(nums.size()<3) return -1;
    sort(nums.begin(),nums.end());
    int p1=nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
    int p2=nums[0]*nums[1]*nums[nums.size()-1];
    return max(p1,p2);
    }
};
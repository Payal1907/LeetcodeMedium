class Solution {
public:
    int minimumCost(vector<int>& nums) {
    int num1 = INT_MAX;
    int num2 = INT_MAX;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<num1){
            num2=num1;
            num1=nums[i];
        }
        else if(nums[i]<num2){
            num2=nums[i];
        }
    } 
    return nums[0]+num1+num2;  
    }
};
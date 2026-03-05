class Solution {
public:
    int findNextGreaterMin(vector<int> nums, int index) {
        int mn = INT_MAX;
        int n = nums.size();
        for(int i=index+1;i<n;i++){
            if(nums[i]>nums[index]){
                mn = min(mn,nums[i]);
            }
        }
        return mn;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    vector<int> rem;
    for(int i=n-1;i>=0;i--){
        int ngm = findNextGreaterMin(nums,i);
        if(ngm==INT_MAX) continue;
        for(int j=n-1;j>i;j--){
            if(nums[j]==ngm){
                std::swap(nums[i],nums[j]);
                break;
            }
        } 
        sort(nums.begin()+i+1,nums.end());
        return;     
    }
    sort(nums.begin(),nums.end());
}
};
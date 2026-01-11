class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        unordered_map<int,int> mp;
        for(int j=i;j<n;j++){
            mp[nums[j]]++;
            sum+=nums[j];
            if(mp.count(sum)) count++;
        }
    }  
    return count;  
    }
};
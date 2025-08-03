class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        int p = -1,q = -1;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==nums[i-1] || nums[i]==nums[i+1]) return false; //should be strictly
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) 
            {
                if(p==-1) p=i; //first maxima
                else return false; //more that one maximas
            }
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1])
            {
                if(q==-1) q=i;
                else return false; //ek se zyada maxima
            }
        } 
        return p!=-1 && q!=-1 && p<q;
        //ek maxima hoga, ek minima hoga aur minima , maxima ke baad aayega 
    }
};
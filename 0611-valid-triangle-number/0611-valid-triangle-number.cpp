class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    int count = 0;
    sort(nums.begin(),nums.end());
    //largest size ko fix krdiya
    int n = nums.size();
    for(int k=n-1;k>=2;k--)
    {
        int j=k-1,i=0;
        while(i<j)
        //jb 
        if(nums[i]+nums[j]>nums[k])
        {
            count+=(j-i);
            //j ko reduce nai kr rhe, i ko increase kr rhe hai, to pehle hi greater hai
            //aur add krne se aur bda ho jayega
            j--;
        } 
        else i++;
    } 
    return count;  
    }
};
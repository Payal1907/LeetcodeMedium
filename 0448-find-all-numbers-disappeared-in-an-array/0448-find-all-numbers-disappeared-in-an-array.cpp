class Solution {
public:
//tujhe map create krne ke zrurat nai hai, jb to array ke andr hi ek trh se ap bna skti hai, dekh 
//index legi nums[i]-1, kyuki n elements hai, thike, agr wo element present hai to uske index pe 
//present element ko negative bna de, aur agr wo nai present to uske index ke element ki value 
//positive hi reh jaayegi, to hm i+1 ko ans me store kr denge, its simple, but so clever!
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for(int i=0;i<nums.size();i++)
    {
        int index = abs(nums[i])-1;
        if(nums[index]>0) nums[index]*=-1;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0) ans.push_back(i+1);
    }
    return ans;
    }
};
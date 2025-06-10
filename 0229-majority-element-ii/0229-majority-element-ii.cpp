//we solved using map, it was easy to solve, but what if we want to solve using constant space 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0;
    int num1 = INT_MIN, num2 = INT_MAX; //we need to get distinct candidates
//moore's voting used, at max there will be 2 majority elements for this condition
    for(auto num : nums)
    {
//order should be you must compare the num first, then check for count
        if(num1==num) count1++;
        else if(num2==num) count2++;
        else if(count1==0) 
        {
            num1 = num;
            count1 = 1;
        }
        else if(count2==0)
        {
            num2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    int majority = nums.size()/3;
    count1 = 0, count2 = 0;
//to recheck if the candidates selected are actually candidates
    for(auto num : nums)
    {
        if(num==num1) count1++;
        else if(num==num2) count2++;
    }
    if(count1>majority) ans.push_back(num1);
    if(count2>majority) ans.push_back(num2);
    return ans;
    }
};
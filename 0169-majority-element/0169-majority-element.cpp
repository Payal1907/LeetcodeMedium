//one way is to sort the elements, since every array has a majority element, the majority element
//occurs more than n/2 times, hence the middlemost element would be majority, since majority
//must cover more than n/2 indexes

//optimal - we have two variables - candidate and the count
//count does not actually store the count of candiate but tells that the candidate will retain  a count of > 0 at the end no matter what, count(x)-count(all other elements)>0
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0, n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(count==0) candidate = nums[i];
            if(nums[i]==candidate) count++;
            else count--;
        }
        return candidate;
    }
};
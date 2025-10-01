class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    unordered_set<int> st(nums.begin(),nums.end());
    int maxi = 0;
    for(auto num : st)
    { 
        if(!st.count(num-1)) //usse chota koi element nai hai, ab uske upr se  
        //check krenge
        { 
            int curr=num+1;
            int count=1;
            while(st.count(curr))
            {
                curr++;
                count++;
            }
            maxi=max(maxi,count);
        }
    }
    //LOOKS LIKE A O(n^2), but can never be since eery elemnt is checked
    //less than n times, so O(n) pe atak jata hai
    return maxi;
    }
};
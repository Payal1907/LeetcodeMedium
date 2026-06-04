class Solution {
public:
    int minOperations(vector<int>& nums) {
       unordered_set<int> st;
       int n = nums.size();
       if(n==1) return 0;
       else if(n==2) return (nums[0]==nums[1])?1:0;
       for(int i=n-1;i>=0;i--){
        if(st.count(nums[i])){
            return i/3 + 1;
        }
        st.insert(nums[i]);
       } 
       return 0;
    }
};
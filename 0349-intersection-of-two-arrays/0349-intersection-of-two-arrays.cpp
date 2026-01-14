class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        unordered_map<int,int> mp;
        for(auto num : nums1) mp[num]++;
        for(auto num : nums2){
            if(mp.count(num)) st.insert(num);
        }
        return vector<int>(st.begin(),st.end());
    }
};
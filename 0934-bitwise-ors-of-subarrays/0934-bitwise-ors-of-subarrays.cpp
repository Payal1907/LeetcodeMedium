class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;
        for(auto num : arr)
        {
            unordered_set<int> curr;
            curr.insert(num);
            for(auto val : prev)
            {
                curr.insert(val|num);
            }
            prev=curr;
            result.insert(curr.begin(),curr.end());
        }
    //har ek index pe end hone waale jitne bhi unique subarrays hai unko ek set me store kregi
        
        return result.size();
    }
};
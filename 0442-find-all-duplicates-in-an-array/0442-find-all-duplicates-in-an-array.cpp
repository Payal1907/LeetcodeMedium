class Solution {
public:
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> news;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1] && 
            find(news.begin(), news.end(), nums[i]) == news.end()) {
            news.push_back(nums[i]);
        }
    }
    return news;
}


};
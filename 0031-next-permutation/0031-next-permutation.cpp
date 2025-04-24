class Solution {
public:
    int findNextGreaterMin(const vector<int>& nums, int index) {
    int target = nums[index];
    int nextGreater = INT_MAX; 
    for (int i = index + 1; i < nums.size(); i++) {
        if (nums[i] > target) {
            nextGreater = min(nextGreater, nums[i]);
        }
    }
    return (nextGreater == INT_MAX) ? -1 : nextGreater; 
}

void nextPermutation(vector<int>& nums) {
    int i = -1, j;
    for (j = nums.size() - 1; j > 0; j--) {
        if (nums[j] > nums[j - 1]) {
            i = j - 1;
            break;
        }
    }
    if(i==-1) reverse(nums.begin(),nums.end()); 
    else
    {
        int min_max = findNextGreaterMin(nums, i);
    for (j = nums.size() - 1; j > i; j--) {  
        if (nums[j] == min_max) {
            swap(nums[i], nums[j]);
            break;
        }
    }
    sort(nums.begin() + i + 1, nums.end());
    }
}

};
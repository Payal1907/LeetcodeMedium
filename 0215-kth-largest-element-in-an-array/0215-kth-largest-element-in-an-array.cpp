class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    if(k>nums.size()) return -1;
    for(int num:nums)
    {
        maxHeap.push(num);
    }  
    for(int i=1;i<k;i++)
    {
        maxHeap.pop();
    } 
    return maxHeap.top();
    }
};
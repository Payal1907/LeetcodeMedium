class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int h, int& count)
    {
        int j=mid+1;
        for(int i=l;i<=mid;i++)
        {
            while(j<=h && nums[i]>2*(long long)nums[j]) {j++;}
            count+=j-(mid+1);
        }
        int size = h-l+1;
        vector<int> temp(size,0);
        int left = l, right = mid+1, k=0;
        while(left<=mid && right<=h)
        {
            if(nums[left]<nums[right]) temp[k++]=nums[left++];
            else temp[k++]=nums[right++];
        }
        while(left<=mid) 
        {
            temp[k++]=nums[left++];
        }
        while(right<=h)
        {
            temp[k++]=nums[right++];
        }
        k=0;
        for(int i=l;i<=h;i++)
        {
            nums[i]=temp[k++];
        }
    }
    void mergeSort(int l, int h, vector<int>& nums, int& count)
    {
        if(l>=h) return;
        int mid=(l+h)>>1;
        mergeSort(l,mid,nums,count);
        mergeSort(mid+1,h,nums,count);
        merge(nums,l,mid,h,count);
    }
    int reversePairs(vector<int>& nums) {
    int count = 0;
    mergeSort(0,nums.size()-1,nums,count);

    /*for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]>2*nums[j]) count++;
        }
    }
    */ 

    return count; 
    }
};
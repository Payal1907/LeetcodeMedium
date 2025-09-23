class Solution {
public:
    bool possible(vector<int> arr,int days,int m, int k)
    {
        int counter = 0;
        int nBouquets = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=days) counter++;
            else
            {
                nBouquets += counter/k;
                counter = 0;
            }
        }
        nBouquets+=counter/k;
        return nBouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = high;
        if(bloomDay.size()<(double)m*k) return -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)) 
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
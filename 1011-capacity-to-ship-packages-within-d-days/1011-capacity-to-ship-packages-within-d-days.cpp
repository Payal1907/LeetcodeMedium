class Solution {
public:
    bool numberOfDays(vector<int>& weights, int mid, int cnt){
        int sum = 0;
        int days = 1;
        int n = weights.size();
        for(int i=0;i<n;i++){
            if(sum+weights[i]<=mid) sum+=weights[i];
            else{
                days++;
                sum=weights[i];
            }
        }
        return days<=cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(numberOfDays(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
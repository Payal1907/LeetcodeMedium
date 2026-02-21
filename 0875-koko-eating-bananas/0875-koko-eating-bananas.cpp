class Solution {
public:
    long long timeToEatAll(vector<int>& piles, int speed)
    {
        long long tt = 0;
        for(int i=0;i<piles.size();i++){
            tt+=(piles[i]+speed-1)/speed;
        }
        return tt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       if(piles.empty()) return -1;
       int low = 1;
       int high = *max_element(piles.begin(),piles.end());
       while(low<=high){
        int mid = low+(high-low)/2;
        if(timeToEatAll(piles,mid)<=h) high=mid-1;
        else low=mid+1;
       }
       return low;
    }
};



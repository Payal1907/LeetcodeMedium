class Solution {
public:
    long long timeToEatAll(vector<int>& piles, int speed)
    {
        long long totalTime = 0;
        for(int i=0;i<piles.size();i++)
        {
            totalTime+=(long long)(piles[i]+speed-1)/speed;
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    if(piles.empty()) return -1;
    int minSpeed = 1;
    int maxSpeed = *max_element(piles.begin(),piles.end());
    while(minSpeed<=maxSpeed)
    {
        int midSpeed = minSpeed + (maxSpeed-minSpeed)/2;
        long long reqTime = timeToEatAll(piles,midSpeed);
        if(reqTime<=h) maxSpeed = midSpeed - 1;
        else minSpeed = midSpeed + 1;
    }
    return minSpeed;   
    }
};



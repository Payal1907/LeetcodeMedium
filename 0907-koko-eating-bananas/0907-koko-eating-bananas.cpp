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
    //min koko 1 kele per hour ki rate se khaa skta hai aur maximum 11 kele per hourse ki rate se
    // see example
    // to ham 1 se 11 speed me sabka check krenge ki, har 1 ... 11 ke liye, wo kitna time le rha hai, agr usse km time me ho rha hai to ham speed aur kam krke dekhenge mtl, high = mid - 1; 
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



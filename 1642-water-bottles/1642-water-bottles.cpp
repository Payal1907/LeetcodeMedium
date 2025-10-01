class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;
    while(numBottles>=numExchange)
    {
        int replace=(numBottles/numExchange);
        ans+=replace;
        int rem = numBottles-(numExchange*replace);
        numBottles=rem+replace;
    }  
    //jaise tu apne hath se math solve krti haina, waise hi krke dekhna
    //sabse pehle to jitni bottle hai utne baar to drink kregi hi
    //phir tu check kregi ki kitne aur bottle replace kr skte hai depending on
    //numExchange ki value
    //ans me usko add kregi
    //phir numbottle ho jayenge = remaining+jitne replace kiye
    return ans;  
    }
};
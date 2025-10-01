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
    return ans;  
    }
};
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
    int i=0,j=0;
    int n = prices.size();
    long long count = 0;
    while(j<n-1)  
    {
        if(prices[j]-prices[j+1]!=1)
        {
            count+=(long long)(j-i+1)*(j-i+2)/2;
            i=j+1;
            j=i;
        }
        else
        {
            j++;
        }
    }
    count+=(long long)(j-i+1)*(j-i+2)/2;
    return count;
    }
};
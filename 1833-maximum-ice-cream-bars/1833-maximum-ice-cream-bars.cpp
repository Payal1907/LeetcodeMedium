class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
    long long sum = 0;
    int n = costs.size();
    int cnt = 0;
    sort(costs.begin(),costs.end());
    for(int i=0;i<n;i++){
        if(sum+costs[i]<=coins){
            sum+=costs[i];
            cnt++;
        }
    }  
    return cnt;  
    }
};
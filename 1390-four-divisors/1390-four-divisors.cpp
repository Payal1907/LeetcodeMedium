class Solution {
public:
//exactly 4 div can be of two form
// 1. 1,p,p^2,p^3 where p is prime
// 2. p*q where p and q are distinct primes
    int sumFourDivisors(vector<int>& nums) {
        int tsum = 0;
        for(auto num : nums){
            int cnt = 0;
            int sum = 0;
            int limit = sqrt(num);
            for(int i=1;i<=limit;i++){
                if(num%i==0){
                    int d1= i;
                    int d2=num/i;
                    sum+=d1;
                    cnt++;
                    if(d1!=d2){
                        sum+=d2;
                        cnt++;
                    }
                }
            }
            if(cnt==4) tsum+=sum;
        }
        return tsum;
    }
};
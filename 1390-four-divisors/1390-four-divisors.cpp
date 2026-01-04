class Solution {
public:
//exactly 4 div can be of two form
// 1. 1,p,p^2,p^3 where p is prime
// 2. p*q where p and q are distinct primes
    vector<int> check(int num)
    {
        vector<int> div;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                div.push_back(i);
                if(i!=num/i) div.push_back(num/i);
            } 
        }
        return div;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            if(num==1) continue;
            vector<int> div = check(num);
            if(div.size()==2){
                sum+=num+1;
                sum+=div[0]+div[1];
            }

        }
        return sum;
    }
};
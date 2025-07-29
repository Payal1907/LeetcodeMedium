class Solution {
public:
    bool checkPrime(int num)
    {
        if(num<=1) return false;
        for(int i=2;i<=std::sqrt(num);i++)
        {
            if(num%i==0)
            {
                return false;
                break;
            }
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        vector<int> prime;
        vector<int> non;
        for(int i=0;i<nums.size();i++)
        {
            if(checkPrime(i)) prime.push_back(nums[i]);
            else non.push_back(nums[i]);
        }
        long long sum1 = 0;
        long long sum2 = 0;
        for(auto num : prime) sum1+=num;
        for(auto num : non) sum2+=num;
        return (long long)abs(sum1-sum2);    
    }
};
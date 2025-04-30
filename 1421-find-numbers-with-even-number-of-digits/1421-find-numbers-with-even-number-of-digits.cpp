class Solution {
public:
int numberOfDigits(int n)
{
    int count = 0;
    while(n>0)
    {
        n=n/10;
        count++;
    }
    return count;

}
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int num : nums)
        {
            if(numberOfDigits(num)%2==0) count++;  
        }
        return count;
        
    }
};
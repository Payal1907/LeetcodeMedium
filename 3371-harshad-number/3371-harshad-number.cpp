class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
    int sum = 0;
    int copy = x;
    while(copy!=0)
    {
        sum=sum+(copy%10);
        copy=copy/10;
    } 
    return (x%sum==0)? sum : -1;  
    }
};
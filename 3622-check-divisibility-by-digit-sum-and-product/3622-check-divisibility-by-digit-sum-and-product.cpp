class Solution {
public:
    bool checkDivisibility(int n) {
    int copy = n;
    int sum = 0;
    int product = 1;
    while(copy!=0)
    {
        product=product*(copy%10);
        sum+=(copy%10);
        copy/=10;
    }   
    return (n%(sum+product)==0); 
    }
};
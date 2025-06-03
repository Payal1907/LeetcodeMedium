class Solution {
public:
    int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    bool negative = (dividend<0) ^ (divisor<0);
    long long divid = abs((long long)dividend);
    long long divi = abs((long long)divisor);
    long long result = 0;
    while(divid>=divi)
    {
        long long temp = divi, multiple = 1;
        while (divid >= (temp << 1)) 
        {
            temp <<= 1;
            multiple <<= 1;
        }
        divid -= temp;
        result += multiple;
    }
    return negative ? -result : result;
    }
};
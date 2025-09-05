class Solution {
public:
    int countBits(long long n)
    {
        int c = 0;
        while(n>0)
        {
            if(n%2==1) c++;
            n=n/2;
        }
        return c;
    }
    int makeTheIntegerZero(int num1, int num2) {  
        for(int k=1;k<=60;k++)
        {
            long long new_num=(long long)num1-1LL*k*num2;
            if(new_num<k) break;
            int bits = countBits(new_num);
            if(bits<=k && k<=new_num) return k;
        }  
        return -1;
    }
};
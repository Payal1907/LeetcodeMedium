class Solution {
public:
//isme hmne pehle set bits count kiye hai, mtlb jitne set bit honge utne 2 ke powers lgenge
//aur num1=sigma 2^k - num2 hai,
//to new_num = num1 - k*num2 hoga
//ek condition yaad rkhna, set bits of new_num should be <= k, and k<=new_num
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
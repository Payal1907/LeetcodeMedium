class Solution {
public:
    const long long mod = 1000000007LL;
    long long modPow(long long base,long long exp)
    {
        base%=mod;
        long long res = 1;
        while(exp>0)
        { //if exponent is odd, then multiply res by base
            if(exp&1)
            {
                res=(res*base)%mod;
            }
            base=(base*base)%mod; //agr even hai to multiply by itself
            exp>>=1; //divide exp by 2
        }
        return res;
    }
    long long factorial(int n)
    {
        long long fact = 1;
        for(int i=2;i<=n;i++)
        {
            fact=(fact*i)%mod;
        }
        return fact;
    }

    int countAnagrams(string s) {
        int n = s.size();
        int start = 0;
        int curr = 0;
        long long anagrams = 1;
        while(curr<=n)
        {
            if(curr==n || s[curr]==' '){
            if(start<curr)
            {
                unordered_map<char,int> freq;
                int len = curr-start;
                for(int k = start;k<curr;k++)
                {
                    freq[s[k]]++;
                }
                long long permutations = factorial(len);
                for(auto pair : freq)
                {
                    long long forEach = factorial(pair.second);
                    long long inverse = modPow(forEach,mod-2);//mod-2 is modular inverse - check
                    //Fermat's little theorem
                    permutations=(permutations*inverse)%mod;
                }
                anagrams=(anagrams*permutations)%mod;
            }
            start=curr+1;
            }
            curr++;
        }
        return (int)anagrams;    
    }
};
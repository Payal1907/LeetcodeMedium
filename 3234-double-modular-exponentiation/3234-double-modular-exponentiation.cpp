class Solution {
public:
long long modPow(long long base,long long exp,long long mod) {
        long long res = 1;
        base=base%mod;
        while (exp) 
        {
            if (exp % 2) 
            {
                res = (res * base) % mod;
                exp = exp - 1;
            } else 
            {
                base = (base * base) % mod;
                exp = exp / 2;
            }
        }
        return res;
    }
    long long calc(int a,int b, int c, int d)
    {
        long long res1 = modPow(a,b,10);
        long long res2 = modPow(res1,c,d);
        return res2;
    }


    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for (int i = 0; i < variables.size(); i++) {
            if (calc(variables[i][0], variables[i][1], variables[i][2], variables[i][3]) ==
                target) {
                res.push_back(i);
            }
        }
        return res;
    }
};
class Solution {
public:
    long long mod = 1e9+7;
    int countPermutations(vector<int>& complexity) {
    int n = complexity.size();
    long long fact = 1;
    int first = complexity[0];
    for(int i=1;i<n;i++)
    {
        if(complexity[i]<=first) return 0;
    }
    for(int i=2;i<n;i++) 
    {
        fact=(fact*i)%mod;
    }
    return (int)fact;
    }
};
class Solution {
public:
    int countPrimes(int n) {
    if (n<=1) return 0;
    vector<int> prime(n, 1);
    prime[0] = prime[1] = 0;
    for (int i=2;i*i<n;i++) 
    {
    //agr ek number prime hai to uska square prime nai hoga, aur uske multiples bhi prime nai honge
    //this is called sieve of eratosthenes
        if (prime[i]) 
        {
            for (int j=i*i;j<n;j+=i) 
            {
                prime[j] = 0;
            }
        }
    }

    int count = 0;
    for (int i=2;i<n;i++) 
    {
        if (prime[i]) count++;
    }
    return count;
}
};
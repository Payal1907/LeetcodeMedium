class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(),happiness.end(),greater<int>());
    int n = happiness.size(); 
    long long sum = 0;
    for(int i=0;i<k;i++)
    {
        int dec = min(happiness[i],i);
        sum+=happiness[i]-dec;
    }
    // cout<<sum<<endl;
    // int times = 0;
    // for(int i=1;i<k;i++)
    // {
    //     sum+=happiness[i];
    //     cout<<sum<<endl;
    //     times=i;
    //     while(times && happiness[i]>0) {happiness[i]--;sum--; times--;}
    //     cout<<sum<<endl;
    // } 
    // cout<<sum<<endl;
    return sum;
    }
};
class Solution {
public:
    int maximumSum(vector<int>& nums) {
    //dekh hr elements ka jo remainder aa hai agr unka sum 3 se divisible huato
    //wo number 3 se divisible hoga
    // (0,0,0), (1,1,1) (2,2,2) (0,1,2)
    vector<int> r0,r1,r2;
    for(auto num : nums)
    {
        int rem = num%3;
        if(rem==0) r0.push_back(num);
        else if(rem==1) r1.push_back(num);
        else r2.push_back(num);
    }
    int mx = 0;
    sort(r0.begin(),r0.end(),greater<int>());
    sort(r1.begin(),r1.end(),greater<int>());
    sort(r2.begin(),r2.end(),greater<int>());
    if(r0.size()>=3) mx=max(mx,r0[0]+r0[1]+r0[2]);
    if(r1.size()>=3) mx=max(mx,r1[0]+r1[1]+r1[2]);
    if(r2.size()>=3) mx=max(mx,r2[0]+r2[1]+r2[2]);
    if(r0.size()>=1 && r1.size()>=1 && r2.size()>=1) 
    {
        mx = max(mx,r0[0]+r1[0]+r2[0]);
    }
    return mx;
    }
};
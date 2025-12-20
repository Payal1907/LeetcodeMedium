class Solution {
public:
    vector<int> countBits(int n) {
    vector<int> ans(n+1); 
    if(n==0) return {0};
    if(n==1) return {0,1}; 
    ans[0]=0;
    ans[1]=1; 
    int last=2;
    for(int num = 2;num<=n;num++)
    {
        if((num&num-1)==0) 
        {
            last=num;
            ans[num]=1;
            continue;
        }
        ans[num]=ans[last]+ans[num-last];
    }
    return ans;
    }
};
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
    vector<int> mxr(n+1,0);
    for(int i=0;i<=n;i++){
        int left = max(0,i-ranges[i]);
        mxr[left]=max(mxr[left],i+ranges[i]);
    }
    int end = 0, farthest=0, cnt=0;
    for(int i=0;i<=n;i++){
        if(i>end){
            if(farthest<=end) return -1;
            end=farthest;
            cnt++;
        }
        farthest=max(farthest,mxr[i]);
    }
    return cnt;
    }
};
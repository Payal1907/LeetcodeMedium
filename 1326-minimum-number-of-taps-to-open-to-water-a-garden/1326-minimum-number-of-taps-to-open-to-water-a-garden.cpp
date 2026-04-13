class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
    vector<vector<int>> rangess;
    for(int i=0;i<=n;i++){
        rangess.push_back({i-ranges[i],i+ranges[i]});
    }   
    sort(rangess.begin(),rangess.end());
    int size = rangess.size();
    int cnt = 0;
    int curr = 0, farthest = 0, i=0;
    while(curr<n){
    while(i<size && rangess[i][0]<=curr){
        farthest=max(farthest,rangess[i][1]);
        i++;
    }
    if(farthest==curr) return -1;
    cnt++;
    curr=farthest;
    }
    return cnt;
    
    }
};
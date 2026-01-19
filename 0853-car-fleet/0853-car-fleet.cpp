class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    if(speed.size()==1) return 1;
    int n = position.size();
    int fleet = 0;
    double pre = 0.0;
    vector<vector<double>> rem(n,vector<double>(2));
    for(int i=0;i<n;i++){
        rem[i][0]=position[i];
        rem[i][1]=(double)(target-position[i])/(double)speed[i];
    }
    sort(rem.begin(),rem.end(), [](const vector<double>&a, const vector<double>&b){return a[0]<b[0];});
    for(int i=n-1;i>=0;i--){
        if(rem[i][1]>pre){
            fleet++;
            pre=rem[i][1];
        }
    }
    return fleet;
    }
};
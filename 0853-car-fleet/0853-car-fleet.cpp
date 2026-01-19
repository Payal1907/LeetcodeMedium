class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    if(speed.size()==1) return 1;
    int n = position.size();
    int fleet = 0;
    double pre = 0.0;
    //last se jo second hai wo last se first wale se uski speed agr zyada hogi aur wo
    //target pohochne se pehle use join krlega tbhi fleet bnegi
    //to pehle atleast jo position hai wo minus krle curr position se
    //aur time nikal liya to aur easy, agr n-1 wale ke paas n-2 se zyada time hua
    //tabhi n-2 usko join kr payega;
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
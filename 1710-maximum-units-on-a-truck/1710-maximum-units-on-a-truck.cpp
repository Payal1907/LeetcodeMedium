class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),comp);
    int ans = 0;
    for(auto box : boxTypes){
        int pick = min(truckSize,box[0]);
        ans+=pick*box[1];
        truckSize-=pick;
    }   
    return ans; 
    }
};
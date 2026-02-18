class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    //for every house we are checking the nearest heater to it
    //for all houses the max(nearest of all one by one taken) is the reqd radius
    sort(houses.begin(),houses.end());
    sort(heaters.begin(),heaters.end());
    int radius = 0;
    for(auto house : houses){
        auto it = lower_bound(heaters.begin(),heaters.end(),house);
        //heater jo nearest hai house ke, greater than equal to
        //ab hr ghr ke liye chek krenge
        int dist1 = INT_MAX, dist2 = INT_MAX;
        if(it!=heaters.end()){
            dist1 = abs(*it - house);
        }
        if(it!=heaters.begin()){
            it--;
            dist2 = abs(*it-house);
        }
        int nearest = min(dist1,dist2);
        radius = max(radius,nearest);
    }
    return radius;
    }    
    
};
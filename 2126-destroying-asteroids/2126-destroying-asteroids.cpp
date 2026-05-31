class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    int n = asteroids.size();
    long long m = mass;
    sort(asteroids.begin(),asteroids.end());
    int i = 0;
    while(i<n){
        if(asteroids[i]>m) return false;
        m+=asteroids[i];
        i++;
    } 
    return true;
    }
};
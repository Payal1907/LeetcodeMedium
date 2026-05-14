class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid){
        int n = tasks.size();
        for(int i=0;i<n;i++){
            int act = tasks[i][0];
            int mini = tasks[i][1];
            if(mid<mini) return false;
            mid-=act;
        }
        return mid>=0;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(),tasks.end(),[&](vector<int>&a, vector<int>&b){
        return a[1]-a[0]>b[1]-b[0];
    });
    int low = 0;
    int high = 1e9;
    int res = 0;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(isPossible(tasks,mid)){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }  
    return res;  
    }
};
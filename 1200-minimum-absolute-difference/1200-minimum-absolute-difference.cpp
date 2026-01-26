class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    int diff = INT_MAX;
    for(int i=0;i<arr.size()-1;i++){
        diff=min(diff,abs(arr[i]-arr[i+1]));
    }    
    for(int i=0;i<arr.size()-1;i++){
        int check = abs(arr[i]-arr[i+1]);
        if(check==diff){
            ans.push_back({arr[i],arr[i+1]});
        }
    }
    return ans;
    }
};
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> count;
        for(int i=0;i<arr.size();i++){
            int num = arr[i];
            int cnt = 0;
            while(num){
                if(num%2!=0) cnt++;
                num=num/2;
            }
            count.push_back({cnt,arr[i]});
        }
        sort(count.begin(),count.end());
        vector<int> ans;
        for(auto cnt : count){
            ans.push_back(cnt.second);
        }
        return ans;         
    }
};
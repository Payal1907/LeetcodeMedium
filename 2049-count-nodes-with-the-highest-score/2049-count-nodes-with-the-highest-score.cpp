class Solution {
public:
    long long mxs = 0;
    int count = 0;
    int n;
    vector<vector<int>> adj;
    int dfs(int node){
        long long score = 1;
        int size = 0; //size of subtree
        for(int child : adj[node]){
            int childSize = dfs(child);
            score*=childSize;
            size+=childSize;
        }
        int rem = n-size-1;
        if(rem>0) score*=rem;
        if(score>mxs){
            mxs=score;
            count=1;
        }
        else if(score==mxs){
            count++;
        }
        return size+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n=parents.size();
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        dfs(0);
        return count;
    }
};
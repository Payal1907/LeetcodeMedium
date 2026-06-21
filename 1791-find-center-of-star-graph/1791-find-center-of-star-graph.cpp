class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
    int n=INT_MIN;
    for(int i=0;i<edges.size();i++){
        n=max(n,edges[i][0]);
        n=max(n,edges[i][1]);
    } 
    vector<vector<int>> adj(n+1);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    for(int i=1;i<=n;i++){
        if(adj[i].size()==n-1) return i;
    }
    return 0;
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> ans;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[v].push_back(u);
    } 
    for(int i=0;i<adj.size();i++){
        if(adj[i].empty()) ans.push_back(i);
    }
    return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans; 
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path){
        int trg = graph.size()-1;
        if(node==trg){
            ans.push_back(path);
            return;
        }
        for(auto nei : graph[node]){
            path.push_back(nei);
            dfs(nei,graph,path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path = {0};   
    dfs(0,graph,path);
    return ans;
    }
};
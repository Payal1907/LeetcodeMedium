class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0);
        int ans = -1;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            unordered_map<int,int> pos;
            int node = i;
            int step = 0;
            while(node!=-1 && !visited[node]){
                visited[node]=1;
                pos[node]=step++;
                node = edges[node];
            }
            if(node!=-1 && pos.count(node)) ans = max(ans,step-pos[node]);
        }  
        return ans;
    }
};
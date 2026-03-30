class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>> adj(n);
      vector<int> mnDist(n,INT_MAX);
      for(auto f : flights){
        adj[f[0]].push_back({f[1], f[2]});
      }
      queue<vector<int>> q;  //stops,node,cost
      q.push({0,src,0});
      while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it[0], node=it[1], cost=it[2];
        if(stops>k) continue;
        for(auto neighbour : adj[node]){
            int nei = neighbour.first;
            int w = neighbour.second;
            if(cost+w<mnDist[nei] && stops<=k){
                mnDist[nei]=cost+w;
                q.push({stops+1,nei,cost+w});
            }
        }
      }
      return (mnDist[dst]==INT_MAX)?-1:mnDist[dst];
    }
};
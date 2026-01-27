class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    int dijkstra(int n) {
    vector<bool> visited(n,false);
    vector<int> dist(n,1e9);
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u]=true;
        for(auto [v,w] : graph[u]){ //jo min element hai uske adj dhoondhenge
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({-dist[v],v}); //becomes min heap
            }
        }
    }
    if(dist[n - 1] == 1e9) return -1;
    return dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges){
        graph.resize(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,2*w});
        }
        return dijkstra(n);
    }
};
class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        pq.push({0,0});
        int edges = 0;
        int cost = 0;
        while(edges<n)
        {
            auto [w,node] = pq.top();
            pq.pop();
            if(visited[node]) continue; //if node is visited
            visited[node]=true; //hr baar visit krne ke baad true
            cost+=w; //uska weight add kr denge
            edges++;

            //ab cost calculated krke push krenge for the node we have visited
            for(int v=0;v<n;v++)
            {
                if(!visited[v])
                {
                    int dist = abs(points[node][0]-points[v][0])+abs(points[node][1]-points[v][1]);
                    pq.push({dist,v});
                }
            }
        } 
        return cost;   
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
    if(heightMap.empty()||heightMap[0].empty()) return 0;
    int m = heightMap.size();
    int n = heightMap[0].size();
    if(m<3||n<3) return 0;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0||j==0||i==m-1||j==n-1)
            {
                pq.push({heightMap[i][j],i,j});
                visited[i][j]=true;
            }
        }
    }
    int total = 0;
    int ds[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    while(!pq.empty())
    {
        auto [height,x,y] = pq.top();
        pq.pop();
        for(auto d : ds)
        {
            int nx = x+d[0], ny=y+d[1];
            if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny])
            {
                visited[nx][ny]=true;
                total+=max(0,height-heightMap[nx][ny]);
                pq.push({max(height,heightMap[nx][ny]),nx,ny});
            }
        }
    }
    return total;
    }
};
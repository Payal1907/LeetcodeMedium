class Solution {
public:
    vector<int> rows = {-1,1,0,0};
    vector<int> cols = {0,0,-1,1};
    int n,m;
    void dfs(int sr, int sc, int c, int color, vector<vector<int>>& image){
        for(int k=0;k<4;k++){
            int nr = sr+rows[k];
            int nc = sc+cols[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==c){
                image[nr][nc]=color;
                dfs(nr,nc,c,color,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc]==color) return image;
    int c = image[sr][sc];
    n = image.size();
    m = image[0].size();
    image[sr][sc]=color;
    dfs(sr,sc,c,color,image);
    return image;
    }
};
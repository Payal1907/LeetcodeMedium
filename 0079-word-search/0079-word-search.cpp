class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    bool helper(int i, int j, string& word, vector<vector<char>>& board,int index){
        if(index==word.size()) return true;
        for(auto& dir : dirs){
            int newi = i+dir[0];
            int newj = j+dir[1];
            //agr us direction me next word nai mila to continue
            if(newi<0||newj<0||newi==n||newj==m||board[newi][newj]!=word[index]) continue;
            char rep = board[newi][newj];
            board[newi][newj]='*';
            if(helper(newi,newj,word,board,index+1)) return true;
            board[newi][newj]=rep;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    char rep = board[i][j];
                    board[i][j]='*';
                    if(helper(i,j,word,board,1)) return true;
                    board[i][j]=rep;
                }
            }
        }
        return false;
    }
};
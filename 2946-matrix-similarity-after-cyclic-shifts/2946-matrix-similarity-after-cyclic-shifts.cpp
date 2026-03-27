class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    k=k%m;
    vector<vector<int>> matrix = mat;
    for(int i=0;i<n;i++){
        if(i%2==0){
            reverse(matrix[i].begin(),matrix[i].end());
            reverse(matrix[i].begin(),matrix[i].begin()+m-k);
            reverse(matrix[i].begin()+m-k,matrix[i].end());
        }
        else{
            reverse(matrix[i].begin(),matrix[i].end());
            reverse(matrix[i].begin(),matrix[i].begin()+k);
            reverse(matrix[i].begin()+k,matrix[i].end());
        }
    }
    return matrix==mat;
    }
};
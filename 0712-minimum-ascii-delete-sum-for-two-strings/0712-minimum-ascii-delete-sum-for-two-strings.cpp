class Solution {
public:
    int m, n;
    int solve(int i,int j,string& s1, string& s2,vector<vector<int>>& tt){
        if(i==m && j==n) return 0; //jb dono string ke end pe phoch gye
        if(i==m){ //s1 ke khtm hogye
        int sum = 0;
        for(int k=j;k<n;k++) sum+=s2[k];
        return sum;
        } 
        if(j==n) {  //s2 ke khtm hogye
        int sum = 0;
        for(int k=i;k<m;k++) sum+=s1[k];
        return sum;
        }
        if(tt[i][j]!=-1) return tt[i][j]; //after base cases
        if(s1[i]==s2[j]) return tt[i][j]=solve(i+1,j+1,s1,s2,tt); 
        //jb elements equal honge to skip
        // if(s1[i]!=s2[j]) 
        int delete_s1_i=s1[i]+solve(i+1,j,s1,s2,tt);
        int delete_s2_j=s2[j]+solve(i,j+1,s1,s2,tt);
        return tt[i][j]=min(delete_s1_i,delete_s2_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        vector<vector<int>> tt(m,vector<int>(n,-1));
        return solve(0,0,s1,s2,tt);
    }
};
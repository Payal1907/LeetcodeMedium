class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int> del;
        for(int i=1;i<strs.size();i++) //rows
        {
            for(int j=0;j<strs[0].size();j++) //cols
            {
                if(del.count(j)>0 || strs[i-1][j]==strs[i][j]) continue;
                if(strs[i-1][j]>strs[i][j]) 
                {
                    del.insert(j);
                    i=0; //i=0 kiya kyuki jb
                    //next col ke liye dekhegi to 0th row se hi start kregi na
                }
                break; 
            }
        }  
        return del.size(); 
    }
};

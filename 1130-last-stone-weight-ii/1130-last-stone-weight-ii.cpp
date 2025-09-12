class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int x : stones)
            sum += x;

        int target = sum / 2;
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));

        for(int i=0;i<n+1;i++) t[i][0]=true;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<target+1;j++)
            {
                if(stones[i-1]<=j) t[i][j]=t[i-1][j-stones[i-1]]||t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        int closest = 0;
        for(int i=target;i>=0;i--)
        {
            if(t[n][i]) 
            {
                closest=i;
                break;
            }
        }
        return sum - 2 * closest;
    }
};
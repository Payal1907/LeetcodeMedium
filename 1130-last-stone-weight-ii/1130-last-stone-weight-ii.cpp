class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int x : stones)
            sum += x;

        int target = sum / 2;
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++)
            t[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (stones[i - 1] <= j)
                    t[i][j] = t[i - 1][j] || t[i - 1][j - stones[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        int closest;
        for (int j = target; j >= 0; j--) {
            if (t[n][j]) {
                closest = j;
                break;
            }
        }

        return sum - 2 * closest;
    }
};
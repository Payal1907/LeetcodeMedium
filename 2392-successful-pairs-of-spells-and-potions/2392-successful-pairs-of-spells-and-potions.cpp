class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        int n = potions.size();
        for(int i=0;i<spells.size();i++)
        {
            int low = 0;
            int high = n;
            while(low<high)
            {
                int mid = low + (high-low)/2;
                long long product= (long long)spells[i]*(long long)potions[mid];
                if(product<success) low=mid+1;
                else high=mid;
            }
            ans.push_back(n-low);
        }
        return ans;

    }
};
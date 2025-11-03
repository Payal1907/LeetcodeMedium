class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
    int needed = 0;
    int maxi = neededTime[0];
    for(int i=1;i<colors.size();i++)
    {
        if(colors[i]==colors[i-1])
        {
            needed+=min(maxi,neededTime[i]);
            maxi=max(maxi,neededTime[i]);
        }
        else maxi=neededTime[i];
    }
    return needed;   
    }
};
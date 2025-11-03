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
    //dekh isme simple cheez hai tune pehle ye check kiya tha ki two consecutive 
    //elements are equal then chose one with lesser needned time
    //but what is three consecutive elements are equal
    //in that case, min one we add to the needed time, but maxi one we store 
    //it for later comparison, if not consecutively equal, then jis element pe
    //presently hai that becomes the maxi for late comparison 
    }
};
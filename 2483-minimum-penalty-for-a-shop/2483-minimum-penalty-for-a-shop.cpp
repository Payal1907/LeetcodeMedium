class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int maxi = 0;
        int score = 0;
        int hour = -1;
        for(int i=0;i<n;i++)
        {
            score+=(customers[i]=='Y')?1:-1;
            if(score>maxi)
            {
                maxi=score;
                hour=i;
            }
        } 
        return hour+1;  
    }
};
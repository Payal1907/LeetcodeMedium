class Solution {
public:
    int remove(string& s, string order, int points)
    {
        int score = 0;
        for(int i = 0; i+1 < s.size();) //ek nayi cheez sikhi tune
        {
            if(s.substr(i,2)==order)
            {
                s.erase(i,2);
                score+=points;
                i=max(0,i-1);
            } 
            else i++;
        }
        return score;
    }
    int maximumGain(string s, int x, int y) {
        int maxi = 0;
        if(x>y)
        {
            maxi+=remove(s,"ab",x);
            maxi+=remove(s,"ba",y);
        }
        else
        {
            maxi+=remove(s,"ba",y);
            maxi+=remove(s,"ab",x);
        }
        return maxi;
        
    }
};
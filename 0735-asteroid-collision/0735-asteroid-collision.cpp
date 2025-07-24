class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for(int asteroid : asteroids)
    {
        bool destroyed = false;
        while(!ans.empty() && asteroid<0 && ans.back()>0)
        {
            if(ans.back()<-asteroid)
            {
                ans.pop_back(); //isme ek ko hi hta rhe hai
                continue;
            }
            else if(ans.back()==-asteroid)
            {
                ans.pop_back(); //isme dono ko hta denge, mtlb aaray waale ko lenge hi nai
            }
            destroyed=true; //ye thired case hai, array waale ki value hi choti hai to destroyed true hoga
            break;
        }
        if(!destroyed) ans.push_back(asteroid);
    } 
    return ans;     
    }
};
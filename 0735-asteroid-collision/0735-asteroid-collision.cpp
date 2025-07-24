class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> ans;
    for(int asteroid : asteroids)
    {
        bool destroyed = false;
        while(!ans.empty() && asteroid<0 && ans.top()>0)
        {
            if(ans.top()<-asteroid)
            {
                ans.pop(); //isme ek ko hi hta rhe hai
                continue;
            }
            else if(ans.top()==-asteroid)
            {
                ans.pop(); //isme dono ko hta denge, mtlb aaray waale ko lenge hi nai
            }
            destroyed=true; //ye thired case hai, array waale ki value hi choti hai to destroyed true hoga
            break;
        }
        if(!destroyed) ans.push(asteroid);
    } 
    //stack wala method uses extra space
    vector<int> result(ans.size());
    for(int i=ans.size()-1;i>=0;i--)
    {
        result[i]=ans.top();
        ans.pop();
    }  
    return result;
    }
};
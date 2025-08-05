class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> placed(baskets.size(),false);
        int count=fruits.size();
        for(int i=0;i<fruits.size();i++)
        {
            for(int j=0;j<baskets.size();j++)
            {
                if(fruits[i]<=baskets[j] && placed[j]==false) 
                {
                    count--;
                    placed[j]=true;
                    break;  
                }
            }
        }
        return count;
    }
};
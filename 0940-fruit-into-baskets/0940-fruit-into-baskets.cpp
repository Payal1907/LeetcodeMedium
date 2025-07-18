class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int maxi = INT_MIN;
    unordered_map<int,int> mp;
    int left = 0;

    for(int right = 0;right<fruits.size();right++)
    {
        mp[fruits[right]]++;
        if(mp.size()>2) //if not possible we make it possible, tabhi dusra case krenge
        {
            while(mp.size()>2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;
            }
        }
        if(mp.size()<=2)
        {
            maxi=max(maxi,right-left+1);

        }
    }
    return maxi;  
    }
};
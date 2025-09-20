class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int zeroes = 1;
    int size = flowerbed.size();
    for(int i=0;i<flowerbed.size();i++)
    {
        if(flowerbed[i]==0) zeroes++;
        else 
        {
            count+=(zeroes-1)/2;
            zeroes=0;
        }
    } 
    zeroes++;
    count+=(zeroes-1)/2;
    return count>=n;   
    }
};
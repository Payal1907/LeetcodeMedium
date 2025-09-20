class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int zeroes = 1; //jo hm ek zeroes count kr rhe the omit krne ke liye agr shur me hua to, isliye 
    // ek pehle se hi le liye ki sabke liye 2 count kre
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
    //similarly jo hm end me ek zero count kr rhe the omit krne ke liye ab hm 2 count kr rhe honge
    count+=(zeroes-1)/2;
    return count>=n;   
    }
};
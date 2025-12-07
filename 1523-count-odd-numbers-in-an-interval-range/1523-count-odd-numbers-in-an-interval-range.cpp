class Solution {
public:
    int countOdds(int low, int high) {
    // int count = 0;
    // for(int i=low;i<=high;i++)
    // {
    //     if(i%2!=0) count++;
    // }
    // return count; 
    int range = (high-low+1); 
    // if(range%2==0) return range/2;
    // else
    // {
    //     if(low%2==0 && high%2==0) return range/2;
    //     else return (range/2) + 1;
    // }
    return (range%2==0)?range/2:((low%2==0 && high%2==0)?range/2:range/2+1);

    }
};
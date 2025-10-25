class Solution {
public:
    int totalMoney(int n) {
    int weeks = n/7;
    int days = n%7;
    //arithmetic series hai ye 28,35,42...
    int sum = 0;
    sum += weeks*28 + (weeks*(weeks-1)/2)*7;
    int start = weeks+1;
    for(int i=0;i<days;i++)
    {
        sum+=(start+i);
    }
    return sum;
    }
};
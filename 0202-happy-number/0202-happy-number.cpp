class Solution {
public:
    bool isHappy(int n) {
        int count = 10;
        if(n==1) return true;
        while(count>0)
        {
            int sum=0;
            int temp=n;
            while(temp!=0)
            {
                int digit=temp%10;
                sum+=digit*digit;
                temp=temp/10;
            }
            n=sum;
            if(n==1) return true;
            count--;
        }   
        return false; 
    }
};
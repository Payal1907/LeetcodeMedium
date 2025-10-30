class Solution {
public:
    bool isPalindrome(int x) {
    int n = x;
    int rev = 0;
    while(n>0)
    {
        int rem = n%10;
        if(rev>(INT_MAX-rem)/10) return false;
        rev=rev*10+rem;
        n=n/10;
    } 
    return rev==x?true:false;   
    }
};
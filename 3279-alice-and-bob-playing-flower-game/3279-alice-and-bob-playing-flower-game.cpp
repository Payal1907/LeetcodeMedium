class Solution {
public:
    long long flowerGame(int n, int m) {
    
    long long n1=n/2,n2=n-n1,m1=m/2,m2=m-m1;
    return n1*m2+n2*m1; //alice picks even, bob picks odd
    //alice picks odd bob picks even
    //Alice picks an even → Bob must pick an odd for Alice to win.
    //Alice picks an odd → Bob must pick an even for Alice to win.

    }
};
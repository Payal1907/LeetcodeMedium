class Solution {
public:
//used in modular exponetiation, binary exponentiation
  double myPow(double x, int n) {
    long long nn = n;
    double ans = 1.0;
    if(nn<0){
        x=1.0/x;
        nn=-nn;
    }
    while(nn>0){
        if(nn&1){ //for odd power
            ans*=x;
        }
        x*=x; //for even power
        nn>>=1;
    }
    return ans;
    }
};
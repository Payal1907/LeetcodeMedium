class Solution {
public:
    int binaryGap(int n) {
    //method 1 : convert to binary and then check for max consecutive 0s 
    //but problem is agr 1 km hue to 
    if(n==1) return 0;
    int last = -1;
    int pos = 0;
    int mx = 0;
    while(n){
        if(n&1){
            if(last!=-1){
            mx=max(mx,pos-last);
            }
            last=pos;
            
        } 
        pos++;
        n=n>>1;
    }
    return mx;
    }
};
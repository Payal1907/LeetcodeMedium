class Solution {
public:
    int numSteps(string s) {
    int carry = 0;
    int cnt = 0;
    for(int i=s.size()-1;i>0;i--){
        if((s[i]=='1')+carry==1){ //bit is odd
        cnt+=2;
        carry=1;
        }
        else cnt+=1;
    }  
    return cnt+carry;
    }
};
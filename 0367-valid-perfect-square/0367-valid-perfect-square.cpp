class Solution {
public:
    bool isPerfectSquare(int num) {
    if(num==1) return true;
    int low =  2, high = num/2;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(num/mid==mid && num%mid == 0) return true;
        else if(num/mid<mid) high=mid-1; //mid*mid>num
        else low=mid+1; //mid*mid<num
    }
    return false;
    }
};
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    string res="";
    if(numerator==0) return "0";
    if((numerator<0) ^ (denominator<0)) res+='-'; //diff signs add -
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);
    res+=to_string(num/den); //the interger part
    long long rem = num%den;
    if(rem==0) return res; //mtlb no fractional part is present
    res+='.'; //if fractional part is present
    unordered_map<long long,int> mp;
    while(rem!=0)
    {
        if(mp.count(rem))
        {
            res.insert(mp[rem],"("); //usi location pe add kr rhe hai
            res+=")"; //last me add krenge
            break;
        }
        mp[rem]=res.size(); //ye track rkhne ke liye ki bracket kaha lgega
        rem=rem*10; //basic long division method me jaise krte hai
        res+=to_string(rem/den); //quotient
        rem=rem%den; //remainder update

    }
    return res;  
    }
};
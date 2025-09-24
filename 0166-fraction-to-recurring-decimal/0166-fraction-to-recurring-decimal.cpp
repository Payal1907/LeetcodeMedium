class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    string res="";
    if(numerator==0) return "0";
    if((numerator<0) ^ (denominator<0)) res+='-';
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
            res.insert(mp[rem],"(");
            res+=")";
            break;
        }
        mp[rem]=res.size();
        rem=rem*10;
        res+=to_string(rem/den);
        rem=rem%den;

    }
    return res;  
    }
};
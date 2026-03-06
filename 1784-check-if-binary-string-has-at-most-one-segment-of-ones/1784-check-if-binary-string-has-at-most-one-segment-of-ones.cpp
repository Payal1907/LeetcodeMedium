class Solution {
public:
    bool checkOnesSegment(string s) {
    //ek trika ye hai ki 01 agr mil gya string me, mtlb 2 segments hai
    //kyuki ye bola hai ki leading zeroes to hai hi nai
    return s.find("01")==string::npos;
    }
};
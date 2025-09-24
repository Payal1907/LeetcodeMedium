class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    string doubled = s+s;
    string cut = doubled.substr(1,doubled.size()-2);
    return cut.find(s)!=string::npos;
    //dekh simple method hai, rotate krne ki bjaye, usko double krke hi aage piche se remove krde ek ek element, agr us doubled-cut me , s present hoga, to true else false
    }
};
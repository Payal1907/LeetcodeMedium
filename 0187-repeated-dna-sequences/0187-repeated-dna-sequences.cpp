class Solution {
public:
//dekh basically har 10 size ki window tujhe leni hai, 2 sets lene hai
//agr jo 10 size ka substring hai wo set me present hai pehle se hi, to use repeated me daal de
//agr nai present hai to seen me daal de, taki aage check kr ske
    vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> seen;
    unordered_set<string> repeated;
    vector<string> result;
    if(s.size()<10) return result;
    for(int i=0;i<=s.size()-10;i++)
    {
        string substr = s.substr(i,10);
        if(seen.count(substr)) repeated.insert(substr);
        else seen.insert(substr);
    }
    for(auto it : repeated)
    {
        result.push_back(it);
    }
    return result;

    }
};
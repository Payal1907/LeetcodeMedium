class Solution {
public:
    string removeDigit(string number, char digit) {
    string maxi="0";
    vector<int> indices;
    for(int i=0;i<number.size();i++)
    {
        if(number[i]==digit) indices.push_back(i);
    }
    for(int i=0;i<indices.size();i++)
    {
        string s =number;
        s.erase(indices[i],1);
        maxi=max(maxi,s);
    }
    return maxi;    
    }
};
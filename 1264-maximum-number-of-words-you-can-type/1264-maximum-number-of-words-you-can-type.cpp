class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    int total = 0;
    bool isbroken = false;
    unordered_set<char> broken(brokenLetters.begin(),brokenLetters.end());
    for(int i=0;i<=text.size();i++)
    {
        if(i==text.size()||text[i]==' ')
        {
            if(!isbroken) total++;
            isbroken = false;
        }
        else if(broken.count(text[i])) isbroken=true;
    }
    return total;    
    }
};
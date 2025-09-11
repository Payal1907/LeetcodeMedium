class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return true;
        return false;
    }
    string sortVowels(string s) {
        string t(s.size(),' ');
        string vowels;
        for(int i=0;i<s.size();i++)
        {
            if(!isVowel(s[i])) t[i]=s[i];
            else vowels.push_back(s[i]);
        }
        sort(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==' ') t[i]=vowels[j++];
        }
        return t;
        
    }
};
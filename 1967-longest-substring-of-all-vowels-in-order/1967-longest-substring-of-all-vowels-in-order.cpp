class Solution {
public:
    int longestBeautifulSubstring(string word) {
    int n=word.size();
    int curr = 0;
    int maxi = 0;
    int vowel = 0;
    for(int i=0;i<n;i++)
    {
        if(i>0 && word[i]<word[i-1]) 
        {
            curr=0;
            vowel=0;
        }
        curr++;
        if(i==0 || word[i]!=word[i-1])
        {
            vowel++;
        }
        if(vowel==5) maxi=max(maxi,curr);
    } 
    return maxi;
    }
};
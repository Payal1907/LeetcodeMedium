class Solution {
public:
//u learnt two things isalnum() and isalpha() for alphanumeric and alphabets
    bool isValid(string word) {
    if(word.size()<3) return false;
    string vowels = "aeiouAEIOU";
    int vowel = 0;
    int consonant = 0;
    for(auto c : word)
    {
        if(!isalnum(c)) return false;
        if(isalpha(c))
        {
            if(vowels.find(c) != string::npos) vowel = 1;
            //npos means c is not found in the string "no position" otherwise would have returned index
            else consonant=1;
        }
    }  
    return (vowel && consonant);
    }
};
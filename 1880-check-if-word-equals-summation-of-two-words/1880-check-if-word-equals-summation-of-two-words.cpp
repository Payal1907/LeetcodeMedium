class Solution {
public:
    int value(string s){
        int val = 0;
        for(int i=0;i<s.size();i++){
            val=val*10+(s[i]-'a');
        }
        return val;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return (value(firstWord)+value(secondWord))==value(targetWord);
    }
};
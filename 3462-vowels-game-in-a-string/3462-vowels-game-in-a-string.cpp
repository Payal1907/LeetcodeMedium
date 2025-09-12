class Solution {
public:
    int count(string s) {
        int vowels = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                vowels++;
            }
        }
        return vowels;
    }
    bool doesAliceWin(string s) {

        if(count(s)==0) return false;
        return true;
    }
};
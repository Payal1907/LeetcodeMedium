class Solution {
public:
string reverseWords(string s) {
    reverse(s.begin(),s.end());
    int n=s.length();
    int i=0;
    while (i < n) {
        while (i < n && s[i] == ' ') {
            i++;
        }
        int j = i;
        while (i < n && s[i] != ' ') {
            i++;
        }
        if (j <= i + 1) {
            reverse(s.begin()+j,s.begin()+i);   
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && (i == 0 || s[i - 1] == ' ')) {
            s.erase(i, 1);
            i--; 
        }
    }
    if (!s.empty() && s.back() == ' ') {
        s.pop_back();
    }
    return s;
}

};
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {
            // rotate by i characters
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated == s)
                return true;
        }
        return false;
    }
};
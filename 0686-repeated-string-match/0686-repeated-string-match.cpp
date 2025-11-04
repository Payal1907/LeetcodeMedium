class Solution {
public:
    void computeLPS(string& pat, vector<int>& lps) {
        int m = pat.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool KMPSearch(string& text, string& pat) {
        int n = text.size();
        int m = pat.size();
        vector<int> lps(m);
        computeLPS(pat, lps);
        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == m)
                return true;
            else if (i < n && text[i] != pat[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string temp = a;
        while (temp.size() < b.size()) {
            temp += a;
            count++;
        }
        if (KMPSearch(temp, b))
            return count;
        temp += a;
        count++;
        if (KMPSearch(temp, b))
            return count;
        return -1;
    }
};
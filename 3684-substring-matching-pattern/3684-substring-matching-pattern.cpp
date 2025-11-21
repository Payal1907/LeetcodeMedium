class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find('*');
        if (x == string::npos) return s == p;
        string prefix = p.substr(0, x);
        string suffix = p.substr(x + 1);
        int i = s.find(prefix);
        int j = s.rfind(suffix);
        return i != -1 && j != -1 && i + prefix.size() <= j;
    }
};


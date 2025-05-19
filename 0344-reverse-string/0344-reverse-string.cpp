class Solution {
public:
    void swap(char* a,char* b)
    {
        char temp= *b;
        *b = *a;
        *a = temp;
    }
    void reversed(vector<char>& s,int l,int r)
    {
        if(l>=r) return;
        swap(&s[l],&s[r]);
        reversed(s,l+1,r-1);
    }
    void reverseString(vector<char>& s) {
    int l = 0, r=s.size()-1;  
    reversed(s,l,r); 
    }
};
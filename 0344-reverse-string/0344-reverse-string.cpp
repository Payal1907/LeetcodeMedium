class Solution {
public:
    void swap(char* a,char* b)
    {
        char temp= *b;
        *b = *a;
        *a = temp;
    }
    void reverseString(vector<char>& s) {
    int l = 0, r=s.size()-1;  
    while(l<r)
    {
        swap(&s[l++],&s[r--]);
    } 
    }
};
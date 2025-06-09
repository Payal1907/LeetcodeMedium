//dekh palindromes 2 type ke hote hai, ya to odd length honge ya to even legnth honge, agr odd
//length hai to tu ek element se hi expand kr skti hai, lekin agr even length hai to center ke 
//do elements consider kregi
class Solution {
public:
    string ans="";
    void expandOnBothSides(string& s, int left, int right)
    {
        while(left>=0 && right<s.size())
        {
//agr kisi point pe elements diff hue to break krle, otherwise aur zoom in(expand) krke check kr
            if(s[left]!=s[right]) break;
            left--;
            right++;
        }
        if(ans.size()<right-left) //maximum length waale ko store krenge hm
        {
            ans=s.substr(left+1,right-left-1); // (right-1)-(left+1)+1
        }
    }
    string longestPalindrome(string s) {
    for(int i = 0;i<s.size();i++)
    {
        expandOnBothSides(s,i,i); //odd palindrome ke liye
        expandOnBothSides(s,i,i+1); //even palindrome ke liye
    }  
    return ans;
    }
};
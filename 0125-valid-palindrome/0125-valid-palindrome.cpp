class Solution {
public:
bool isPalindrome(string s) {
    string s_clear;
    
    
    for (char c : s) {
        if (isalnum(c)) { 
            s_clear += tolower(c); 
        }
    }

  
    int left = 0, right = s_clear.size() - 1;
    while (left < right) {
        if (s_clear[left] != s_clear[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
};
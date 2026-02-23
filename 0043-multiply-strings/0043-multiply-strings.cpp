class Solution {
public:
    string multiply(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();
    string ans(n+m,'0');
    int res = 0;
    int rem = 0;
    for(int j=m-1;j>=0;j--){
        int rem = 0;
        for(int i=n-1;i>=0;i--){
            int n1 = num2[j] - '0'; //for char , string hota to stoi use krte
            int n2 = num1[i] - '0';
            int pos = i+j+1;
            int sum = (ans[pos]-'0')+(n1*n2)+rem;
            ans[pos]=(sum%10)+'0';
            rem=sum/10;
        }
        ans[j]+=rem;    
    }  
    int start = 0;
    while(start<ans.size()-1 && ans[start]=='0') start++;
    return ans.substr(start);  
    }
};
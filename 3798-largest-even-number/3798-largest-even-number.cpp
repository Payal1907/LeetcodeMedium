class Solution {
public:
    string largestEven(string s) {
    int n = s.size();
    int index = n-1;
    for(int i=n-1;i>=0;i--){
            if(s[i]=='2') {
                index=i;
                break;
            }
        }
    return (index!=n-1)?(s.substr(0,index+1)):((s[index]=='2')?s:"");
    }
};
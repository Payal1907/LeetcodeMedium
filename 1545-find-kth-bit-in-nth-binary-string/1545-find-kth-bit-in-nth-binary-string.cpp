class Solution {
public:
    string invert(string s){
        string ans = "";
        for(auto ch : s){
            ans+=((ch=='0')?'1':'0');
        }
        return ans;
    }
    string reversed(string s){
        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string prev = "0";
        for(int i=2;i<=n;i++){
            string neww;
            neww=prev+"1"+reversed(invert(prev));
            prev=neww;
        }
        return prev[k-1];
    }
};
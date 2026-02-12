class Solution {
public:
    int longestBalanced(string s) {
    int count = 1;
    int n = s.size();
    for(int i=0;i<n;i++){
        vector<int> freq(26,0);
        int unique = 0;
        int maxi = 0;
        int cntmx = 0;
        for(int j=i;j<n;j++){
            int f = ++freq[s[j]-'a'];
            unique+=(f==1);
            if(f>maxi) {
                maxi=f;
                cntmx = 1;
            }
            else if(f==maxi) cntmx++;
            if(unique==cntmx) count=max(count,j-i+1);
        }
    } 
    return count;   
    }
};
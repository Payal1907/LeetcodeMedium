class Solution {
public:
    bool check(string& a, string& b)
    {
        int m = a.size();
        int n = b.size();
        for(int i=0;i<=m-n;i++)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(a[i+j]!=b[j]) break;
            }
            if(j==n) return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int m = a.size();
        int n = b.size();
        int times = 1;
        string temp = a;
        while((int)temp.size()<n)
        {
            temp+=a;
            times++;
        }
        if(check(temp,b)) return times;
        temp+=a;
        times++;
        if(check(temp,b)) return times;
        return -1;
    }
};
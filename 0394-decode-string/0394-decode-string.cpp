class Solution {
public:
    string decodeString(string s) {
    stack<int> freq;
    stack<string> ch;
    string curr="";
    int i=0;
    while(i<s.size())
    {
        if(isdigit(s[i]))
        {
            int count=0;
            while(isdigit(s[i]))
            {
                count=count*10+(s[i]-'0');
                i++;
            }
            freq.push(count);
        }
        else if(s[i]=='[')
        {
            ch.push(curr);
            curr="";
            i++;
        }
        else if(s[i]==']')
        {
            string temp=ch.top();
            ch.pop();
            int times = freq.top();
            freq.pop();
            for(int j=0;j<times;j++)
            {
                temp+=curr;
            }
            curr=temp;
            i++;
        }
        else
        {
            curr+=s[i];
            i++;
        }
    }
    return curr;
    }
};
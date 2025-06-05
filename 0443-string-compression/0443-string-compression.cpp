class Solution {
public:
    int compress(vector<char>& chars) {
    int n = chars.size();
    int i = 0, write = 0;
    while(i<n)
    {
        char curr = chars[i];
        int count = 0;
        while(i<n && chars[i]==curr)
        {
            i++;
            count++;
        }
        chars[write++]=curr;
        if(count>1)
        {
            string s = to_string(count);
            for(auto c : s)
            {
                chars[write++]=c;
            }
        }
    }
    return write;
    }
};
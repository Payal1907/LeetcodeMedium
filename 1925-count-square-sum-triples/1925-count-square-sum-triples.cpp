class Solution {
public:
    int countTriples(int n) {
    int count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int square = i*i+j*j;
            int root = sqrt(square);
            int check = root*root;
            if(root>n) break;
            else if(check==square) count++;
        }
    }  
    return count*2; 
    }
};
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    sort(capacity.begin(),capacity.end(),greater<int>()); 
    int i = 0;
    int sum = accumulate(apple.begin(),apple.end(),0);
    int curr = 0;
    int count = 1;
    while(curr<sum)  
    {
        if(curr+capacity[i]<sum)
        {
            curr+=capacity[i];
            i++;
            count++;
        }
        else break;
    } 
    return count;
    }
};
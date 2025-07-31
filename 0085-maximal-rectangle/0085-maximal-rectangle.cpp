class Solution {
public:
    int largestRectangle(vector<int> arr)
    {
        vector<int> nse(arr.size(),arr.size());
        vector<int> pse(arr.size(),-1);
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        int maxi = 0;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(maxi,arr[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> prefixSum(n,vector<int>(m, 0));  
    for(int j=0;j<m;j++)
    {
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][j]=='1') sum+=1;
            if(matrix[i][j]=='0') sum=0;
            prefixSum[i][j]=sum;
        }
    } 
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,largestRectangle(prefixSum[i]));
    }
    return maxi;
    }
};
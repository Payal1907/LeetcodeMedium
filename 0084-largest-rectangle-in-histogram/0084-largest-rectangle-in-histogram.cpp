class Solution {
public:
    vector<int> findNSE(vector<int> arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int> arr)
    {
        int n = arr.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxi = 0;
        for(int i=0;i<heights.size();i++)
        {
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        } 
        return maxi;      
    }
};
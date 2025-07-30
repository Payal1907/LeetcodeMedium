class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n,n); //for elements with no next smaller, last index+1 is next smaller
        vector<int> pse(n,-1);
        int maxi = 0;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();  
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }

        for(int i=0;i<heights.size();i++)
        {
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        } 
        return maxi;      
    }
};
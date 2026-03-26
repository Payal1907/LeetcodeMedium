class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    //nse
    int n = prices.size();
    vector<int> dis(n,0);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& st.top()>prices[i]){
            st.pop();
        }
        if(!st.empty()) dis[i]=st.top();
        st.push(prices[i]);
    }
    for(int i=0;i<n;i++){
        dis[i]=prices[i]-dis[i];
    }
    return dis;
    }
};
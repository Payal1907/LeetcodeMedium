class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
    int n =nums.size();
    vector<int> nge(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]<nums[st.top()]) {
                st.pop();
        }
        if(!st.empty()) nge[i]=st.top();
        st.push(i);
    }
    while(!st.empty()){st.pop();}
    vector<int> nse(n,n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]>nums[st.top()]) {
                st.pop();
        }
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    while(!st.empty()){st.pop();}
    vector<int> pge(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]<=nums[st.top()]) {
                st.pop();
        }
        if(!st.empty()) pge[i]=st.top();
        st.push(i);
    }
    while(!st.empty()){st.pop();}
    vector<int> pse(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]>=nums[st.top()]) {
                st.pop();
        }
        if(!st.empty()) pse[i]=st.top();
        st.push(i);
    }
    long long mx = 0, mn = 0;
    for(int i=0;i<n;i++){
        long long left = i-pge[i];
        long long right = nge[i]-i;
        mx+=1LL*nums[i]*left*right;
    }
    for(int i=0;i<n;i++){
        long long left = i-pse[i];
        long long right = nse[i]-i;
        mn+=1LL*nums[i]*left*right;
    }
    return abs(mx-mn);
    }
};
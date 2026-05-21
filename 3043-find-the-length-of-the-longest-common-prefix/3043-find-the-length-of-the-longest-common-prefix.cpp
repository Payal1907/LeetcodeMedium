class Solution {
public:
    int digits(int n){
        int cnt = 0;
        while(n>0){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> st;
    for(auto num : arr1){
        int x = num;
        while(x>0){
            st.insert(x);
            x/=10;
        }
    }  
    int ans = 0;
    for(auto num : arr2){
        int x = num;
        int len = digits(num);
        while(x>0){
            if(st.count(x)){
                ans=max(ans,len);
                break;
            }
            x/=10;
            len--;
        }
    }
    return ans;
    }
};
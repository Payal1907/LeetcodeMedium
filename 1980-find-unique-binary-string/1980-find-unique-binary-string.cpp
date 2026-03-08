class Solution {
public:
    // int toDeci(string s){
    //     int num = 0;
    //     int power = 1;
    //     for(int i=s.size()-1;i>=0;i--){
    //         num+=(s[i]-'0')*power;
    //         power=power*2;
    //     }
    //     return num;
    // }
    string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    string ans = "";
    for(int i=0;i<n;i++){
        if(nums[i][i]=='1') ans+='0';
        else ans+='1';
    }
    //    0 1
    //0:  0 1
    //1:  1 0
    //this is called cantor's diagonal argument

    return ans;
    }
};
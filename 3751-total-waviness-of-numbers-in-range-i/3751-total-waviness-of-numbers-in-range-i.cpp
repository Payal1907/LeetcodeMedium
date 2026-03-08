class Solution {
public:
    int count(int num){
        int cnt = 0;
        string s = to_string(num);
        for(int i=1;i<s.size()-1;i++){
            if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1]&&s[i]<s[i+1])) cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
    int cnt = 0;   
    for(int num=num1;num<=num2;num++){
        if(num<100) continue;
        cnt+=count(num);
    } 
    //why brute works here
    //100000*4=400000 - at max 4 digits honge beech me
    return cnt;
    }
};
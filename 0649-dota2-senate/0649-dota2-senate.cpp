class Solution {
public:
    string predictPartyVictory(string s) {
    queue<int> r,d;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='R') r.push(i);
        else d.push(i);
    }
    while(!r.empty() && !d.empty()){
        int i1 = r.front();
        int i2 = d.front();
        r.pop(); d.pop();
        if(i1<i2) r.push(n+i1);
        else d.push(n+i2);
    }
    return !r.empty()?"Radiant":"Dire";
    // if(s[n-1]!=q.front()){
    //     q.pop();
    //     q.push(s[n-1]);
    // }
    // while(q.size()>1){
    //     char curr = q.front();
    //     q.pop();
    //     if(q.size()>1) char next = q.front();
    //     else return q.front()=='R'?"Radiant":"Dire";
    //     if(curr==next) q.push(curr);
    // }
    // return "";   
    }
};
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    sort(hBars.begin(),hBars.end());
    sort(vBars.begin(),vBars.end());
    int cons = 1, vcons = 1, mx = 1, vmx = 1;
    //dekh kyuki hme squares hi khali krne hai to jitne max horizontal consecutive hone
    //aur jitne max vertical consecutive honge,  utna area bda hoga
    for(int i = 1;i<hBars.size();i++){
        if(hBars[i]-hBars[i-1]==1){
            cons+=1;
            mx=max(cons,mx);
        }
        else cons = 1;
    }   
    for(int i=1;i<vBars.size();i++){
        if(vBars[i]-vBars[i-1]==1){
            vcons+=1;
            vmx=max(vmx,vcons);
        }
        else vcons=1;
    }
    return pow(min(mx,vmx)+1,2); //area of square - un dono ka minimum kyuki common hi
    //rectangle bnayega na
    }
};
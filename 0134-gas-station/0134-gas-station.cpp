class Solution {
public:
//bhot simple ques hai, tko bs hr index pe jaake dekhna hai, ki tank me last me >=0 kuch bcha hona chahiye
//agr final_gas final_cost se kam hoga to simple si baat hai aisa koi index exist nai krta;
//agr tank me 0 se km balance hai kisi point pe, to agle index ko answer maanege hm, wo aage pta chl jaayega ans
//hoga ki nai wo
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_gas=0;
    int total_cost=0;
    int index=0;
    int tank=0;
    for(int i=0;i<gas.size();i++){
        total_gas+=gas[i];
        total_cost+=cost[i];
        tank+=(gas[i]-cost[i]);
        if(tank<0){
            index=i+1;
            tank=0;
        }
    }
    if(total_gas<total_cost) return -1;   
    return index;
    }
};
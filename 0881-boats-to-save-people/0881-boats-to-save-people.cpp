class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    int boats = 0;
    sort(people.begin(),people.end());
    int i=0,j=people.size()-1;
    while(i<=j){
        if(people[i]+people[j]<=limit){
            i++;
        }
        j--;
        boats++;
    }



    // for(int i=0;i<people.size()-1;i+=2){
    //     if(people[i]+people[i+1]>limit){
    //         boats+=2;
    //     }
    //     else boats++;
    // }
    return boats;
    }
};
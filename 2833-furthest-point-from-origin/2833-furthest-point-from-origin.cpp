class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
    int left = 0, right = 0, blank = 0;
    for(char move : moves){
        if(move=='L') left++;
        else if(move=='R') right++;
        else blank++;
    }
    return abs(left-right)+blank;
    }
};
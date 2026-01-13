class Solution {
public:
    double Ab(vector<vector<int>>& squares, double y){
        double area = 0.0;
        for(const auto& sq : squares){ //dont copy every time
        //COPYING each square every iteration (very expensive)
            double bottom = sq[1];
            double side = sq[2];
            double top = bottom+side;
            if(y<=bottom) area+=side*side;
            else if(y<top) area+=(top-y)*side; //paritally above
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
    double low = 1e9;
    double high = -1e9;
    double total_area=0.0;
    int mn=0;
    for(auto sq : squares){
        total_area+=1.0*sq[2]*sq[2];
        low = min(low,(double)sq[1]);
        high = max(high,(double)(sq[1]+sq[2]));
    }
    double trg = total_area/2.0;
    while(high-low>1e-5){ //reduce iterations
        double mid = low+(high-low)/2.0;
        double above = Ab(squares,mid);
        if(above>trg) low=mid; //line too below - move up
        else high=mid;
    }  
    return low;
    }
};
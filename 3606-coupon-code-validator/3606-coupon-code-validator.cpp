class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    vector<string> ans;
    int n = code.size();
    unordered_map<string,int> businessSorted = {
        {"electronics",0},
        {"grocery",1},
        {"pharmacy",2},
        {"restaurant",3}
    };
    vector<pair<pair<int,string>,string>> sortable;
    for(int i=0;i<n;i++) 
    {
        if(!isActive[i]) continue;
        if(businessSorted.find(businessLine[i])==businessSorted.end()) continue;
        if(code[i].empty()) continue;
        bool valid = true;
        for(char c : code[i])
        {
            if(!(isalnum(c)|| c=='_'))
            {
                valid=false;
                break;
            }
        }
        if(valid==false) continue;
        int sortIndex = businessSorted[businessLine[i]];
        sortable.push_back({{sortIndex,code[i]},code[i]});
    }  
    sort(sortable.begin(),sortable.end());
    for(auto p : sortable)
    {
        ans.push_back(p.second);
    }
    return ans;
    }
};
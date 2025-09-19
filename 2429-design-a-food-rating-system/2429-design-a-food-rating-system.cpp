class FoodRatings {
public:
    unordered_map<string,string> food_cuisine;
    unordered_map<string,int> food_rating;
    //unordered_map<string,priority_queue<pair<int,string>>> cuisine_pq; max heap
    
    //comparator bnana
    //true - a will come after b;
    //false - a will come before b;
    struct cmp{
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if(a.first==b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>, cmp>>       cuisine_heap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int n = foods.size();
    for(int i=0;i<n;i++)
    {
        food_cuisine[foods[i]]=cuisines[i];
        food_rating[foods[i]]=ratings[i];
        cuisine_heap[cuisines[i]].push({ratings[i],foods[i]});
    }    
    }
    
    void changeRating(string food, int newRating) {
        food_rating[food]=newRating;
        string cuisine = food_cuisine[food];
        cuisine_heap[cuisine].push({newRating,food});    
    }
    
    string highestRated(string cuisine) {
        auto& pq = cuisine_heap[cuisine];
        while(!pq.empty())
        {
            auto [rating,food]=pq.top();
            if(food_rating[food]==rating) return food;
            pq.pop(); //outdated entries jo additional hai unhe remove kr rhe hai
        }
        return "";    
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
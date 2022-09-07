class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>mp;
    unordered_map<string,string>hp;
    unordered_map<string,int>rt;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int j=0;
        for(int i=0;i<cuisines.size();i++)
        {
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
            hp[foods[i]]=cuisines[i];
            rt[foods[i]]=ratings[i];
        }
        
    }
    
    void changeRating(string food, int newRating) {
        auto fr=rt[food];
        mp[hp[food]].erase({-fr,food});
        mp[hp[food]].insert({-newRating,food});
        rt[food]=newRating;
        
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
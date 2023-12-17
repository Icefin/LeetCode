class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for (int i = 0; i < n; ++i) {
            string& food = foods[i];
            string& cuisine = cuisines[i];
            int rating = ratings[i];
            
            m_food_rating[food] = rating;
            m_food_cuisine[food] = cuisine;
            m_cuisine_order[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string& cuisine = m_food_cuisine[food];
        int rating = m_food_rating[food];
        
        m_cuisine_order[cuisine].erase(m_cuisine_order[cuisine].find({-rating, food}));
        m_cuisine_order[cuisine].insert({-newRating, food});
        m_food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return m_cuisine_order[cuisine].begin()->second;
    }
    
private :
    unordered_map<string, int> m_food_rating;
    unordered_map<string, string> m_food_cuisine;
    unordered_map<string, set<pair<int, string>>> m_cuisine_order;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
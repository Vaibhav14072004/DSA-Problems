class FoodRatings {
    unordered_map<string,int> foods;
    vector<string> ss;
    vector<string> fs;
    vector<int> rs;
    unordered_map<string,set<pair<int,int>>> mp;
public:
    FoodRatings(vector<string>& f, vector<string>& s, vector<int>& ratings) {
        for(int i=0 ; i<s.size() ; i++) {
            mp[s[i]].insert({ratings[i] , i});
            foods[f[i]] = i;
        }
        rs = ratings;
        ss = s;
        fs = f;
    }
    
    void changeRating(string food, int newRating) {
        int idx = foods[food];
        mp[ss[idx]].erase({rs[idx],idx});
        mp[ss[idx]].insert({newRating,idx});
        rs[idx] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto &mySet = mp[cuisine];  

// highest element
auto maxi = *mySet.rbegin();  
string ans = fs[maxi.second];  

// check ties with same score
for (auto it = mySet.rbegin(); it != mySet.rend(); ++it) {
    if (it->first != maxi.first) break;  
    ans = min(ans, fs[it->second]);  
}
return ans;

    }
};







// TC= BUILD O(N), UPDATE O(1) QUERY O(N)

// Brute Force Approach
// Total TC= O(Queries* N) > 10^8 ->> giving TLE
/*

class FoodRatings {
public:
    unordered_map<string,string> foodMap;  // food -> cuisines
    unordered_map<string,int> ratingMap;   // food -> ratings

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n= foods.size();
        for(int i=0; i<n; i++)
        {
           foodMap[foods[i]]= cuisines[i];
           ratingMap[foods[i]]= ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        ratingMap[food]= newRating;
    }
    
    string highestRated(string cuisine)
    {
        string ans= "";
        int maxRating= -1;
        for(auto &it: ratingMap)
        {
            if(foodMap[it.first] != cuisine) continue;
            if(it.second > maxRating)
            {
                ans= it.first;
                maxRating= it.second;
            }

            else if(it.second== maxRating && it.first < ans)
            {
                ans= it.first;
            }
        }
      return ans;  
    }
};

*/

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
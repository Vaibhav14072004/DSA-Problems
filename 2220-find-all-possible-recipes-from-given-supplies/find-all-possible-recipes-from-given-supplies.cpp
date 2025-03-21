class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, unordered_set<string>> g;
        unordered_map<string, int> inDeg;
        for(int i = 0; i < n; i++) {
            // recipes[i]: bread
            for(string& ingredient: ingredients[i]) {
                // ingredient: flour
                // flour -> bread
                g[ingredient].insert(recipes[i]);
                inDeg[recipes[i]]++;
            }
        }
        queue<string> q;
        for(string &supply: supplies) {
            if(!inDeg[supply]) {
                q.push(supply);
            }
        }
        string ingredient;
        while(!q.empty()) {
            ingredient = q.front();
            // ingredient: flour
            q.pop();
            for(auto &cd: g[ingredient]) {
                // cd: bread
                // flour -> bread
                // Decrease the indegree on "bread". Means 1 less item is required to make it.
                inDeg[cd]--;
                if(inDeg[cd] == 0) {
                    q.push(cd);
                }
            }
        }
        vector<string> ans;
        for(string &recipe: recipes) {
            if(!inDeg[recipe]) {
                ans.push_back(recipe);
            }
        }
        return ans;
    }
};
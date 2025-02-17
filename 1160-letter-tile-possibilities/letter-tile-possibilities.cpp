// Ques of BackTracking

// Approach 1 ->> Using Unordered_set

// TC= O(N!)  as we have N*(N-1)*(N-2)..  possiblity for each place
// SC= O(N* N!) + O(N) is recursive stack space

class Solution {
public:
    void solve(unordered_set<string> &st, vector<bool> &used,string &tiles,string &curr){
        st.insert(curr);
        
        // we have run loop bcoz we have to again start from beginning
        // Ex- str= "AAB" then we can also get "ABA", order not matters
        for(int i=0; i<tiles.size(); i++)
        {
            if(used[i]){
                continue;
            }

            used[i]= true;
            curr+= tiles[i];
            solve(st,used,tiles,curr);

            // backtracking...
            curr.pop_back();
            used[i]= false;
        }
    }

    int numTilePossibilities(string tiles) {
        int n= tiles.size();
        unordered_set<string> st;
        vector<bool> used(n,false);
        
        string curr= "";
        solve(st,used,tiles,curr);

        // {} string is not allowed
        return st.size()-1; 
    }
};
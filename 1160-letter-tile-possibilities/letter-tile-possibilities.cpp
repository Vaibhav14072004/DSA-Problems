// Ques of BackTracking

// Approach 2 ->> Using 26 sized vector instead using set
// TC= O(N!)
// SC= O(26)

class Solution{
public:
    void solve(vector<int> &freq,int &cnt)
    {
        cnt++;
        for(int i=0; i<26; i++)
        {
            if(freq[i]== 0){
              continue;
            }

            freq[i]--;
            solve(freq,cnt);
            
            // backtracking...
            freq[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        int n= tiles.size();
        vector<int> freq(26,0);

        for(int i=0; i<n; i++){
            freq[tiles[i]-'A']++;
        }
        
        int cnt= 0;
        solve(freq,cnt);
        return cnt-1;
    }
};




// Approach 1 ->> Using Unordered_set

// TC= O(N!)  as we have N*(N-1)*(N-2)..  possiblity for each place
// SC= O(N!) + O(N) is recursive stack space

/*

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

*/
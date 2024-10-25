// Ques of BackTracking....

// Pruning (To make optimized) -->> If we break the rem n-i characters separately, we cannot get max of 
// currCnt + (n- i), but if maxCnt is already greater than our curr cnt, no need to explore this case further
// as max Cnt will not get updated later..

//  TC= O(N* 2^N)
// SC= O(N)

class Solution {
public:
    void solve(int i,string str, unordered_set<string> &st,int currCnt, int &maxCnt)
    {
        // base case
        if(i >= str.length())
        {
            maxCnt= max(maxCnt,currCnt);
            return;
        }

        // To make it more optimized (pruning)
        if(maxCnt >= currCnt + str.length()-i)
        {
           return;
        }
   
        for(int j=i; j<str.length(); j++)
        {
           string curr= str.substr(i,j-i+1);
           if(st.find(curr) == st.end())
           {
               st.insert(curr);
               solve(j+1, str,st,currCnt+1, maxCnt);

               // backtracking...
               st.erase(curr);
           }
        }
    }

    int maxUniqueSplit(string str) {
        int n= str.length(); 
        unordered_set<string> st;
        int maxCnt= 0, currCnt= 0;

        solve(0,str,st,currCnt,maxCnt);
        return maxCnt;
    }
};




/*

class Solution {
public:
    int maxCnt = 0;
    unordered_set<string_view> seen; 
    void backtrack(int index, string s, int cnt){
        if (cnt + (s.size() - index) <= maxCnt) return; 
        if(index == s.size()) {
            maxCnt = max(maxCnt, cnt);
            return;
        };

        for(int i = index; i < s.size(); i++) {
            std::string_view substr(s.data() + index, i - index + 1); 
            // similar to `s.substr(i, i - index + 1);` but more efficient
            if(seen.count(substr)) continue;
            seen.insert(substr);
            backtrack(i + 1, s, cnt + 1);
            seen.erase(substr);
        }
    }
    int maxUniqueSplit(string s) {
        backtrack(0, s, 0);
        return maxCnt;
    }
};

*/
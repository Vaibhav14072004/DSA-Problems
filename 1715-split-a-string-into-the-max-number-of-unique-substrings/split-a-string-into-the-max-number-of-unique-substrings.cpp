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

// Ques of Backtracking... (DO, EXPLORE, UNDO)

// Approach 2 ->> Using cnt variable...
// TC= O[3* 2^(N-1)]
// SC= O(N) for recursive stack space

class Solution{
  public:
    void solve(int &cnt,string &ans,string &curr,int n, int k)
    {
        // base case
        if(curr.size()== n)
        {
            cnt++;
            if(cnt== k)
            {
                ans= curr;
            }
            return;
        }

        for(char ch= 'a'; ch<= 'c'; ch++)
        {
            // adjacent chars should NOT be equal..
            if(!curr.empty() && curr.back()== ch){
                continue;
            }

            curr+= ch;
            solve(cnt,ans,curr,n,k);
            
            // backtracking...
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k){
        int cnt= 0;
        string ans= "";
        string curr= "";
        solve(cnt,ans,curr,n,k);
        return ans;  
    }
};









// Approach 1 -> Storing all strings ..

// TC= O[3* 2*2*2..... upto n-1] ->> 3* 2^(N-1)
// SC= O(N) for recursive stack + O[N* 2^N] bcoz there will be 2^N strings in ans vector and each string is of size n

// TC= O[1.5* 2^N] ->> O(2^N)
// SC= O(N* 2^N)

/*

class Solution {
public:
    void solve(vector<string> &ans,string &curr, int n, int k)
    {
        // base case
        if(curr.size()== n){
            ans.push_back(curr);
            return;
        }

        for(char ch= 'a'; ch<= 'c'; ch++)
        {
            // adjacent chars must be different..
            if(!curr.empty() && curr.back()== ch){
                continue;
            }
            curr+= ch;           // DO
            solve(ans,curr,n,k); // EXPLORE

            // backtracking...  UNDO
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k){
        vector<string> ans;
        string curr= "";
        solve(ans,curr,n,k);

        if(ans.size() < k){
            return "";
        }
        return ans[k-1];
    }
};

*/
// Ques of Backtracking... (DO, EXPLORE, UNDO)
// TC= O[3* 2*2*2..... upto n-1] ->> 3* 2^(N-1)
// SC= O[N* 2^N] bcoz there will be 2^N strings in ans vector and each string is of size n

// TC= O[1.5* 2^N] ->> O(2^N)
// SC= O(N* 2^N)

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
            curr+= ch;
            solve(ans,curr,n,k);

            // backtracking...
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
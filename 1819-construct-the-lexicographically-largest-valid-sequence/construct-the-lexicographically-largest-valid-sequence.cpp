// Ques of Backtracking..
// TC= O(N!) ->> N*(N-1)*(N-2) ... possiblities for each place

class Solution {
public:
    bool solve(int i,int n,vector<int> &ans, vector<bool> &used)
    {
        // base case
        if(i>= ans.size()){
            return true;
        }

        if(ans[i]!= -1)
        {
            return solve(i+1,n,ans,used);
        }

        for(int num= n; num>=1; num--)
        {
            if(used[num]){
                continue;
            }

            used[num]= true;
            ans[i]= num;
            
            // Two cases arise ->> if no is 1 or (from 2 to n)
            if(num== 1)
            {
                if(solve(i+1,n,ans,used)){
                    return true;
                }
            }
            
            // if no is > 1, we have to put it on (i+num) th index also
            else
            {
                int j= i+num;
                if(j< ans.size() && ans[j]== -1)
                {
                    ans[j]= num;
                    if(solve(i+1,n,ans,used)){
                        return true;
                    }

                    // backtrack...
                    ans[j]= -1;
                }
            }

            // backtrack...
            used[num]= false;
            ans[i]= -1;
        }
    return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,-1);
        vector<bool> used(n+1,false);

        solve(0,n,ans,used);
        return ans;
    }
};
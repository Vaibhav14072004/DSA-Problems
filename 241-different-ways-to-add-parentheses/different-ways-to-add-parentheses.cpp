// Approach 1 -> Every operator has 2 possibilities, either continue moving or do the operation
// TC= O(N* 2^N)

class Solution {
public:
    vector<int> solve(string str)
    {
        int n= str.length();
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            if(str[i]== '+' || str[i]== '-' || str[i]== '*')
            {
                vector<int> leftResult= solve(str.substr(0,i));
                vector<int> rightResult= solve(str.substr(i+1));

                // add all possible combinations that can be formed by leftResult and righResult in vector
                for(int &x: leftResult)
                {
                    for(int &y: rightResult)
                    {
                        if(str[i]== '+')
                        {
                            ans.push_back(x+y);
                        }
                        else if(str[i]== '*')
                        {
                            ans.push_back(x*y);
                        }

                        // if str[i]== '-'
                        else
                        {
                            ans.push_back(x-y);
                        }
                    }
                }
            }
        }
        
        // if there was no operator, ex- 12, directly push it in ans..
        if(ans.empty())
        {
            ans.push_back(stoi(str));
        }
     return ans;
    }
    

    vector<int> diffWaysToCompute(string str) {
        return solve(str);
    }
};





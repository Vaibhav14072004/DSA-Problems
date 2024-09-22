class Solution 
{
    int numOfChildren(long long int i, int n)
    {
        int childs = 0;
        long long int lower = i * 10;
        long long int upper = i * 10 + 9;
        while (lower <= n)
        {
            childs += min((long long int)n, upper) - lower + 1;
            lower *= 10;
            upper = upper * 10 + 9;
        }
        return childs;
    }
    void dfs(long long int i, int n, int& l, int& elem)
    {
        if(i>n)
            return;
        if(l==0)
        {
            elem = i;
            return;
        }
        for(int j = 0; j <= 9; j++)
        {
            long long int k = i*10 + j;
            if(k<=n)
            {
                int c = numOfChildren(k,n) + 1;
                if(l - c > 0)
                {
                    l -= c;
                    continue;
                }
                else
                {
                    l--;
                    dfs(k,n,l,elem);
                    break;
                }
            }
            else
                break;
        }
    }
public:
    int findKthNumber(int n, int k)
    {
        int elem, childs = 0;
        for(int i = 1; i <= 9; i++)
        {
            int c = numOfChildren(i,n) + 1;
            if(c + childs < k)
            {
                childs += c;
                continue;
            } 
            else
            {
                k = k - childs - 1;
                dfs(i,n,k,elem);
                break;
            }
        }
        return elem;
    }
};








// ------  TLE ----------

// Approach 2 -> Without using vector
// TC= O(N)
// SC= O(log 10 (n)) ->> recursive stack space that will store go upto digits in n

/*

class Solution{
public:
    void solve(int curr, int n, int &k, int &ans)
    {
        // base case
        if(curr > n){
           return;
        }

         k--;
        if(k== 0)
        {
           ans= curr;
           return;
        }
       
        // now try to append other digit starting from 0 ->> 1 10 11 12 ...
        for(int append= 0; append<=9; append++)
        {
           int newNo= (curr*10+ append);
           if(newNo > n){
              return;
           }

           solve(newNo, n, k,ans);
           if(k== 0){
             return;
           }
        }
    }

    int findKthNumber(int n, int k){
        int ans= -1;
        for(int i=1; i<=9; i++)
        {
           solve(i,n,k,ans);
           if(k== 0) break;
        }
      return ans;
    }
};

*/



// ------  TLE -----

// Approach 1 -> Using vector
// TC= O(N)
// SC= O(N)+ O[log 10 (n)] -> vec + recursive stack that will upto depth = to digits in n 

/*

class Solution {
public:
   void solve(int curr, int n, int k, vector<int> &ans)
   {
       // base case
       if(curr > n){
         return;
       }

       ans.push_back(curr);

       // now try to append other digit starting from 0 ->> 1 10 11 12 ...
       for(int append= 0; append <= 9; append++)
       {
            int newNo= (curr*10 + append);
            if(newNo > n){
                return;
            }

         solve(newNo, n, k, ans);
       }
   } 

    int findKthNumber(int n, int k) {
        vector<int> ans;
        for(int i=1; i<=9 ; i++)
        {
            solve(i,n,k,ans);
        }
        return ans[k-1];
    }
};

*/
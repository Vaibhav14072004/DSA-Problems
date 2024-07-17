// Optimised 2 Pointers Approach
// TC= O(N)  SC= O(1)

class Solution{
public:
 bool checkValidString(string str) {
        int n= str.size();
        int openCount= 0, closeCount= 0;

        for(int i=0; i<n; i++)
        {
            // calculate openCount from start of array..
            if(str[i]== '(' || str[i]== '*')
            {
                openCount++;
            }
            else
            {
              openCount--; 
            }
        
        // calculate closeCount from last of array...
            if(str[n-i-1] == ')' || str[n-i-1]== '*')
            {
               closeCount++;
            }
            else
            {
                closeCount--;
            }
    
    // If any of the openCount or closeCount has negative value... return false 
        if(openCount< 0 || closeCount< 0) return false;
        }

   return true;
 }
};






// Approach 3 -> Using 2 Stacks -> Beats 100 % users in C++
// TC= O(N)  SC= O(N)

/*

class Solution{
public:
 bool checkValidString(string str) {
        int n= str.size();
        stack<int> openPar;
        stack<int> asterick;

        for(int i=0; i<n; i++)
        {
            if(str[i]== '(')
            {
                openPar.push(i);
            }

            else if(str[i]== '*')
            {
                asterick.push(i);
            }
        
        // if(str[i]== ')') ->> first check if we have openParethesis in stack... then pop out 
        // but if openParenthesis is Empty and asterisk is NOT Empty... then use that asterisk
            else 
            {
               if(openPar.size()> 0) openPar.pop();
               else if(asterick.size() > 0) asterick.pop();
               else {
              return false;
                }
            }
        }

        // ONE CASE TO HANDLE Remaining case...  if there is No close ')' bracket left...
        // But openParenthesis != empty and asterisk != empty...
       // Then openParenthesis should comes before asterick ->>  ( * =>> () =>> BALANCED OUT 
       // But if asterisk comes before openParenthesis ->> return false =>> * ( =>> CANNOT balanced out   

        while(!openPar.empty() && !asterick.empty())
        {
            // if openParenthesis comes after * =>> Means value of openPar > value of * =>> return false
            if(openPar.top() > asterick.top()){
         return false;
            } 

            openPar.pop();
            asterick.pop();
        }
        
// If NO OpenParenthesis is left out ->> * can be converted into "" ->> So return true
return openPar.empty();
 }
};

*/





// Approach 2 -> Using 2D DP -> Beats 5 % users only
// TC of recursive approach -> 3^n
// TC of DP Approach -> O(N^2)
// SC of DP Approach -> O(N^2)

/*

class Solution{
public:
    bool solve(int index, int openParenthesis, string str, vector<vector<int>> &dp)
    {
        int n= str.size();

        // base case
        if(index>= n)
        {
            return openParenthesis== 0;
        }

        if(dp[index][openParenthesis] != -1)
        {
            return dp[index][openParenthesis];
        }
    
    bool ans= false;
    if(str[index]== '(')
    {
       ans= solve(index+1, openParenthesis+1, str, dp);
    }

    else if(str[index]== ')')
    {
        if(openParenthesis > 0)
        // we can also write ans |= solve(index+1, openParenthesis-1,str,dp)
        ans= ans || solve(index+1, openParenthesis-1, str, dp);
    }

// when str[index]== '*'.... 3 cases arise
    else
    {
       bool case1= solve(index+1, openParenthesis+1, str,dp);
       
       bool case2= false;
       if(openParenthesis > 0)
       {
         case2= solve(index+1, openParenthesis-1, str,dp);
       }

       bool case3= solve(index+1, openParenthesis, str,dp);
       ans= case1|| case2|| case3;
    }

return dp[index][openParenthesis]= ans;
    }


    bool checkValidString(string str) {
        int n= str.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(0,0,str,dp);
    }
};

*/





// Approach 1 (2 Pointers)

/*

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0;
        }
        
        return leftMin == 0;
    }
};

*/
// Approach 2 ->> Without stack
// Cnt of '(' from left to right should never be -ve
// Cnt of ')' from right to left should never be -ve

// TC= O(N)
// SC= O(1)

class Solution{
public:
     bool canBeValid(string str, string locked) {
        int n = str.length();

        // base case
        if(n % 2== 1)
        {
            return false;
        }

        // cnt of opening bracket '(' should never be -ve, from left to right
        int open= 0;
        for(int i=0; i<n; i++)
        {
            if(locked[i]== '0' || str[i]== '('){
                open++;
            }
            else if(str[i]== ')'){
                open--;
                if(open < 0)
                {
                    return false;
                }
            }
        }
        
        // cnt of closing ')' should never be -ve, from right to left
        int closed= 0;
        for(int i=n-1; i>=0; i--)
        {
            if(locked[i]== '0' || str[i]== ')'){
                closed++;
            }
            else if(str[i]== '('){
                closed--;
                if(closed < 0)
                {
                    return false;
                }
            }
        }
    return true;
     }
};






// Approach 1 -> Using Stack
// TC= O(N)
// SC= O(N)

/*

class Solution {
public:
    bool canBeValid(string str, string locked) {
        int n = str.length();
        
        // base case ->> if len of str is odd,return false
        if(n % 2 == 1)
        {
            return false;
        }

        // stack to store index of fixed '(' open bracket, locked= 1
        stack<int> fixedOpenStack;

        // vector to store indexes of those '(' or ')' having locked= 0
        vector<int> notFixed;

        for (int i = 0; i < n; i++) 
        {
            if (locked[i] == '0') 
            {
                notFixed.push_back(i);
            }

            // if locked[i]== '1', its direction can be changed
            else
            {
                if(str[i] == '(') 
                {
                    fixedOpenStack.push(i);
                }

                // str[i]== ')' 
                else
                {
                    if(!fixedOpenStack.empty())
                    {
                        fixedOpenStack.pop();
                    }
                    else if(!notFixed.empty())
                    {
                        notFixed.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        
        // after finishing iterating the entire string...

        // if stack is NOT empty && vector is NOT empty 
        while(!fixedOpenStack.empty() && !notFixed.empty() && fixedOpenStack.top() < notFixed.back())
        {
            fixedOpenStack.pop();
            notFixed.pop_back();
        }

        if(fixedOpenStack.empty() && notFixed.size() % 2 == 0)
        {
            return true;
        }
      return false;  
    }
};

*/
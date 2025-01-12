// Approach 1 -> Using Stack
// TC= O(N)

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
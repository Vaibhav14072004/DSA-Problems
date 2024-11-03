// Approach 2 -> Brute Force Approach
// Generate all strings by shifting one character..

// TC= O(N^2)

class Solution{
public:
    bool rotateString(string str, string goal) {
       if(str== goal)
       {
          return true;
       }

       if(str.length() != goal.length())
       {
          return false;
       }

       for(int i=1; i<= str.length(); i++)
       {
           // rotate func takes 3 parameters, middle parameter is the inex from which we have to rotate
           rotate(str.begin(), str.begin()+1, str.end());
           if(str== goal)
           {
              return true;
           }
        }
          return false;  
       }
};







// Approach 1 
// TC= O(N)

/*

class Solution {
public:
    bool rotateString(string str, string goal) {
        if(str== goal)
        {
            return true;
        }

        if(str.length() != goal.length())
        {
            return false;
        }
        
        str+= str;
        if(str.find(goal) != string::npos)
        {
            return true;
        }
        return false;
    }
};

*/
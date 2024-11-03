// Approach 1 
// TC= O(N)

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
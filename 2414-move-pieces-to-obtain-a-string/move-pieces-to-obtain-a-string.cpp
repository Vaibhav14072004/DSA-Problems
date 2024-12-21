// Optimized Approach ->> 2 Pointers
// TC= O(N)

class Solution{
  public:
    bool canChange(string start, string target) {
        int n= start.length();

        int i=0, j= 0;
        while(i< n || j < n)
        {
            // skip the spaces _ in start string
            while(i< n && start[i]== '_'){
                i++;
            }

            // skip the spaces in target string
            while(j< n && target[j]== '_'){
                j++;
            }
            
            // if both strings are finished, return true
            if(i== n && j== n){
                return true;
            }
            
            // if any one of the string got finished but other is NOT, return false
            if(i== n || j== n){
              return false;
            }
 
            if(start[i] != target[j]){
                return false;
            }
            
            // start= 'L_'   target= '_L', we cannot make start = target
            if(start[i]== 'L' && i<j)
            {
                return false;
            }

            // start= '_R'  target= 'R_', we cannot make start= target
            if(start[i]== 'R' && i>j)
            {
                return false;
            }

            i++;
            j++;
        }
       return true; 
    }
};








//  ----- TLE ------
// Brute Force Approach
// TC= O(2^N)

/*

class Solution {
public:
    bool solve(string &start, string &target, unordered_map<string,bool> &mp)
    {
        int n= start.length();
        if(start== target)
        {
            return true;
        }
        
        // if this state is already known
        if(mp.count(start))
        {
            return mp[start];
        }

        for(int i=0; i<n; i++)
        {
            if(i-1 >= 0 && start[i]== 'L' && start[i-1]== '_')
            {
                swap(start[i-1],start[i]);

                if(solve(start,target,mp)){
                    return true;
                }
                 
                // backtracking...
                swap(start[i-1],start[i]);
            }

            else if(i+1 < n && start[i]== 'R' && start[i+1]== '_')
            {
                swap(start[i],start[i+1]);

                if(solve(start,target,mp)){
                    return true;
                }

                // backtracking...
                swap(start[i+1],start[i]);
            }
        }
    return mp[start]= false;
    }


    bool canChange(string start, string target) {
        int n= start.length();

        unordered_map<string,bool> mp;
        return solve(start,target,mp);
    }
};

*/
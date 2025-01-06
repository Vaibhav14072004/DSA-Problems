/*
   **** [DIFFERENCE ARRAY METHOD] ****
    
    Query=  [L, R, val]

    diff[L] += val
    diff[R+1] -= val

    TC= O(N), Instead of again and again iterating array for diff indices, [To prevent TC= O(N*Q)]
    directly do ans[L]+= val and ans[R+1] -= val
    and then find cummulative sum which will give final changes required..  
*/


// Approach 2 -> Optimized
// Difference Array Method (of MIK)
// TC= O(N + Q)

class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& shifts) {
        int n= str.length();
        
        vector<int> diff(n,0);
        for(int i= 0; i<shifts.size(); i++)
        {
           int leftIdx=  shifts[i][0];
           int rightIdx= shifts[i][1];

           // if shifts[i][2]== 0, move leftwards...
           int val= -1; 
           
           // moving rightwards..
           if(shifts[i][2]== 1){
              val= 1;
           }

            diff[leftIdx]+= val;

            if(rightIdx+ 1 < n){
                diff[rightIdx + 1] -= val;
            }
        }
        
        int currSum= 0;
        string ans= "";

        for(int i=0; i<n; i++)
        {
            currSum= (currSum + diff[i]) % 26;
            if(currSum < 0){
                currSum+= 26;
            }

            int temp= ((str[i]-'a') + currSum) % 26;
            ans+= (temp+ 'a');
        }
        return ans; 
    }
};
 









//  ----- TLE ------
// Approach 1 ->> Brute Force Aproach 
// TC= O(N* Q)

/*

class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& shifts) {
        int n= str.length();

        vector<int> diff(n,0);
        for(int i=0; i<shifts.size(); i++)
        {
            int leftIdx= shifts[i][0];
            int rightIdx= shifts[i][1];
            int val= shifts[i][2];

            for(int j= leftIdx; j<= rightIdx; j++)
            {
                // moving leftwards..
                if(val== 0){
                  diff[j]-= 1;
                }

                // moving rightwards...
                else{
                  diff[j]+= 1;
                }
            }
        }

        string ans= "";
        for(int i=0; i<n; i++)
        {
            int shift= diff[i] % 26;
             
             // OR we can also do..
             // if(shift < 0) shift+= 26;

            int temp= (((str[i]-'a') + shift)+ 26) % 26;
            ans+= temp + 'a';
        }
       return ans; 
    }
};

*/
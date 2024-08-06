// Aproach 3 -> Using map
// TC= O(N)
// SC= O(N)

class Solution {
public:
    int minimumPushes(string word){
        int n= word.length();

        unordered_map<int,int> mp;
        int digitNo= 2;
        
        int ans= 0;
        for(int i=0; i<n; i++)
        {
            if(digitNo > 9)
            {
                digitNo= 2;
            }
            mp[digitNo]++;
            ans+= mp[digitNo];
            digitNo++;
        }
      return ans;  
    }
};






// Optimized Approach 
// TC= O(N)
// SC= O(1)

/*

class Solution{
public:
  int minimumPushes(string word)
    {
        int n= word.length();
        
        int ans= 0;
        for(int i=0; i<n; i++)
        {
            ans+= 1 + (i/8);
        }
    return ans;
    }
};

*/






// Approach 1 

// TC= O(N/8) ->> O(N)
// SC= O(N)

/*

class Solution {
public:
    int minimumPushes(string word){
        int n= word.length();
       long long ans= 0;

       // we can accumulate 8 chars on first place of 8 buttons..
       if(n <= 8)
       {
          return n;
       } 

       // one double press needed... if all 8 buttons first place got filled 
       else
       {
           int rem= n;
           int i= 1;
           while(rem > 0)
           {
               if(rem >= 8)
               {
                   rem-= 8;
                   ans+= 8*i;
               }
               else
               {
                  ans+= rem*i;
                  rem= 0;
               }
            i++;
           }
       }

    return static_cast<int> (ans);
    }
};

*/
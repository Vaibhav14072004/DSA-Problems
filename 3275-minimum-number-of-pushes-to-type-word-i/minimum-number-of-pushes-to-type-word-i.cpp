// Given that all letters appear only once... so we have taken set 

// TC= O(N) + O(N/8) for while loop

// TC= O(N)
// SC= O(N)

class Solution {
public:
    int minimumPushes(string word){
        int n= word.length();

        unordered_set<char> st;
        for(int i=0; i<n; i++)
        {
            st.insert(word[i]);
        }

       long long ans= 0;

       // we can accumulate 8 chars on first place of 8 buttons..
       if(st.size() <= 8)
       {
          return st.size();
       } 

       // one double press needed... if all 8 buttons first place got filled 
       else
       {
           int rem= st.size();
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
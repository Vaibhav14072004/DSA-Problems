// Optimized Way of Writing the above code...
// TC= O(N)

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts){
        int n= shifts.size();
        
        long long totalShift= 0;
        for(int i=n-1; i>=0; i--)
        {
           totalShift= (totalShift + shifts[i]) % 26;

           s[i]= ((s[i]- 'a' + totalShift) % 26) + 'a';
        }
        return s;
    }
};




// Approach -> Using prefix array + Shifting operation
// TC= O(N)

/*

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts){
        int n= shifts.size();

        string ans(n,' ');
   
        for(int i=n-1; i>=0; i--)
        {
            // We have to shift all the characters till that index in each shift...
            if(i< n-1)
            {
               shifts[i]+= shifts[i+1] % 26;
            }

            char ch= s[i];
            int shift= shifts[i] % 26;
            char shiftedChar= ((ch-'a'+ shift) % 26)+ 'a';

            // make reverse string as output...
            ans[i]= shiftedChar;

            // Giving MLE ->> ans= shiftedChar + ans
        }
       return ans; 
    }
};

*/
/*
   First find frequencies of all chars and store it in map or freq vector...
   Those chars having freq < k cannot be part of any sequence, so make their freq as 0

   maxLen of each sequence can be maxLen= (n/k)

   This is freq of chars can be there in each sequence.. 
   if(freq[i] > k)  (requiredFreq= freq[i]/k)

   Now with this requiredFreq generate all possible sequences...
   and check whether this (sequence appended k times is subsequence of string str or NOT)
*/


// Approach 1 -> Generating all possible subsequences
// TC= ->> (N/k)! for generating sequence of length N/k and O(N) for checking subsequence..

// TC= O(N)* O(N/k)!
// SC= O(26)+ O(N)



class Solution {
public:
   // function to find whether (curr string appended k times) is subsequence of str or NOT...
    bool isSubsequence(string &str, string &curr,int k)
    {
        int n= str.length();
        int m= curr.length();
        int i=0, j=0;

        while(i < n && j < m*k)
        {
            if(str[i]== curr[j % m]){
                i++;
                j++;
            } 
            else{
              i++;
            } 
        }
        return j== m*k;
    }


   void backtracking(string curr,string &result,vector<int> &requiredFreq,int &maxLen, int &k,string &str)
   {
       // base case
       if(curr.length() > maxLen){
          return;
       }

       if(isSubsequence(str,curr,k))
       {
           if(curr.length() > result.length() || ((curr.length()== result.length()) && curr > result)){
              result= curr;
           }
       }

       // now create each subsequence.. starting from 'z' to make as large as possible..
       // Using BackTracking...
       for(int i=25; i>=0; i--)
       {
           if(requiredFreq[i]== 0){
              continue;
            }
          
          // DO
          curr+= (i+ 'a');
          requiredFreq[i]--;

          // EXPLORE
          backtracking(curr,result,requiredFreq,maxLen,k,str);

          // UNDO
          curr.pop_back();
          requiredFreq[i]++;
       }
   }

    string longestSubsequenceRepeatedK(string str, int k) {
        int n= str.length();

        vector<int> freq(26,0);
        for(int i=0; i<n; i++){
            freq[str[i]-'a']++;
        }
        
        // This is required freq that can be used for making each sequences..
        vector<int> requiredFreq(26,0);
        for(int i=0; i<26; i++)
        {
            if(freq[i] < k){
               freq[i]= 0;
            }
            else{
               requiredFreq[i]= freq[i]/k;
            }
        }

        // Each sequence can be of this length..
        int maxLen= n/k;

        string result= "";
        string curr= "";
        backtracking(curr,result,requiredFreq,maxLen,k,str);

     return result;
    }
};
/*
   First find frequencies of all chars and store it in map or freq vector...
   Those chars having freq < k cannot be part of any sequence, so make their freq as 0

   maxLen of each sequence can be maxLen= (n/k)

   This is freq of chars can be there in each sequence.. 
   if(freq[i] > k)  (requiredFreq= freq[i]/k)

   Now with this requiredFreq generate all possible sequences...
   and check whether this (sequence appended k times is subsequence of string str or NOT)
*/


// Approach 2 -> Better way to erite backtracking function....
// TC= O(N)* O(N/k)!
// TC= O(N/k) + O(26)

class Solution{
 public:
    bool isSubsequence(string &str,string &curr,int &k)
    {
        int n= str.length();
        int m= curr.length();
        int i=0, j= 0;

        while(i < n && j < m*k)
        {
            if(str[i]== curr[j % m]){
                j++;
            }
          i++;
        }
      return (j== m*k);  
    }


    bool backtracking(string &curr,string &result,int len,string &str,vector<int> &freq,int k)
    {
       // base case
       if(curr.length()== len)
       {
           if(isSubsequence(str,curr,k))
           {
              result= max(result,curr);
              return true;
           }
          return false; 
       }

       // start making lexographically largest by starting from 'z' to 'a'
       for(int i=25; i>=0; i--)
       {
           if(freq[i]== 0){
              continue;
           }

           // DO
           curr+= i + 'a';
           freq[i]--;

           // EXPLORE
           if(backtracking(curr,result,len,str,freq,k))
           {
              return true;
           }

           // UNDO
           curr.pop_back();
           freq[i]++;
       }
      return false; 
    }


    string longestSubsequenceRepeatedK(string str, int k) {
        int n= str.length();

        vector<int> freq(26,0);
        for(int i=0; i<n; i++){
            freq[str[i]-'a']++;
        }

        for(int i=0; i<26; i++)
        {
            if(freq[i] < k){
                freq[i]= 0;
            }

            // this is the required freq for making each sequence
            else
            {
              freq[i]= freq[i]/k;
            }
        }

        // Each sequence can be of maxLen= n/k
        int maxLen= n/k;

        string curr= "";
        string result= "";

        // instead of making string curr from 0, start making it from maxLen
        for(int len=maxLen; len>=0; len--)
        {
            // first subsequence will be result as it will be of max possible length 
            //and lexographically largest as we start making string curr starting from 'z' to 'a'

            vector<int> tempFreq= freq;
            if(backtracking(curr,result,len,str,tempFreq,k))
            {
                result= curr;
                break;
            }
        }
      return result;  
    }
};








// Approach 1 -> Generating all possible subsequences...
// TC= ->> (N/k)! for generating sequence of length N/k and O(N) for checking subsequence..
// SC= O(N/k) for recursive stack space..

// TC= O(N)* O(N/k)!
// SC= O(26)+ O(N/k) 

/*

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

*/
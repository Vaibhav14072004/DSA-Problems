
/*
Intuition ->> After doing operation 0, kth char will be same as (k - len/2)th char
     bcoz len becomes double after each operation copying same values...

    After doing operation1, kth char will be next coming character after 
    (k-len/2)th character ...
    
    So after the length of the curr string becomes (len >= k), break....
*/


// Approach -> Using Recursion find the kth char then apply operation ...

// TC= O(log k)
// SC= O(log k)


class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n= operations.size();
        
        // base case..
        if(k== 1){
            return 'a';
        }

        long long len= 1; // 'a'
        long long newk= -1;
        int operation= -1;

        for(int i=0; i<n; i++)
        {
            // after each operation len becomes double..
             len= len*2;

             if(len >=k)
             {
                operation= operations[i];
                newk= k- len/2;   
                break; 
             }
        }

       char ch= kthCharacter(newk,operations);
         
        // if operation= 1, return next character...
        // IMP NOTE ->> return (ch-'a'+1)+ 'a' will give error if k is very large... 

        if(operation== 1){
          return ch== 'z' ? 'a' : ch+1;
        }
     
     // if operation= 0, return same character as it is...
     return ch;
    }
};






/* ----- Giving TLE -------

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n= operations.size();
        string word= "a";
        for(int i=0; i<n; i++)
        {
            if(word.size() >= k) break;

            if(operations[i]== 0)
            {
                word+= word;
            }
            else
            {
                string temp= "";
                for(int i=0; i<word.length(); i++)
                {
                    int val= ((word[i]-'a')+1) % 26;
                    char ch= val+ 'a';
                    temp+= ch;
                }
                word+= temp;   
            }
        }
      return word[k-1];  
    }
};

*/




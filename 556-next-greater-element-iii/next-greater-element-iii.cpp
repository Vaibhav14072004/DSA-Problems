/*
Ques ->> To find just largest no (Smaller than all larger numbers formed) using the digits of given no

## IMP Point ->> We cannot make smaller no if all digits of it are in increasing order from end
Ex- 321 
    All possible combinations are:- 123,132, 213, 231,312 ->> All are smaller 
    NO Smaller no possible in this case...


--------------   INTUITION   ---------------------

Traverse from end, increment i till the point it follows increasing order...
Stop i  at index, where the curr digit is NOT greater than its next digit...

Now swap this digit with just greater digit in its right part
After swapping, just reverse all digits after it...

EX->  4  5  2  6  5  4
                     ^              
                     i

Now start traversing string from end,
Till the point it stops following increasing order..

     4  5  2  6  5  4
           ^
           i

    Now swap this digit with just greater digit in its right portion...
    So swap (2, 4) 

    4  5  {4}  6  5  {2}   
               ---------    

    Now reverse the remaining portion after that digit..

    4  5  4  2  5 6  ->> Smallest greater no 
    
--------------------------------------------------------------------
      
   .... STL Functions...

to_string() ->> Used to convert int to string

stoi() ->> Used to convert string to int

stoll()  ->> Used to convert string to long long int

*/

// TC= O(N)

class Solution {
public:
    int nextGreaterElement(int n){

        // first convert int to string..
        string no= to_string(n);
        
        int len= no.length();
        int i= len-2;
        
        // increment i till the point it follows increasing order....
        while(i >= 0 && no[i] >= no[i+1])
        {
             i--;
        }
        
     // If the no is in increasing order from end.. It is NOT possible to find greater no than it
        if(i== -1)
        {
            return -1;
        }

        // Now swap i with just greater element on its right..
        int j= len-1;
        while(j>i && no[i] >= no[j])
        {
            j--;
        }

        swap(no[i], no[j]);

        string ans= "";

        // we have to include till index i.. that is (i+1) elements from 0th index
        ans+= no.substr(0,i+1); 
       
      // Now reverse all digits after index-> i.. 
        for(int k= len-1; k> i; k--)
        {
            ans+= no[k];
        }
        
        // convert ans string into long long int..
        long long output= stoll(ans);

        // if the ouput does not lie in range of 32 bit integer, return -1
        if(output> INT_MAX)
        {
            return -1;
        }

        return (int)output;
    }
};
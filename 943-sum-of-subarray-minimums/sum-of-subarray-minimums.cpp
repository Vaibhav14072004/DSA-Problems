// Approach 2 -> Optimized -> Using stack

/*   ----- INTUITION ------
 
Find {next smaller element} and {previous smaller element} 
for each element of array...

    <----   left elements=  (i - prev Smaller[i]) ->>>>

will give no of elements on left side (including curr element)
that are greater than or equal to curr element...

    <----  right elements=  (next Smaller[i] - i)  ->>>>

will give no of elements on right side (including curr element)
that are greater than or equal to curr element

Multiply [rightElements * leftElements]
Now multiply above sum with arr[i] value....

    (left * right)* arr[i] ->> 

will give no of {total no of subarrays such that curr element as minimum in that subarrays)


******   BASE CASE  ******

If there is a duplicate element... in that way we will count it in both ways 
(from left as well as right)

->>> So find any one of with >= and other with only >
 
1. next Smaller element with >=  but prev smaller element with only >
2. next Smaller element with > but prev smaller element with >=
  

Ex-  
        Suppose we need to find all subarrays for 3 for which it is min element...
Index-  0    1   2   3   4   5   6   7

       1    4    6   7   {3}   7   8   1
               L         ^  R
           -------------- -------
              4-0=> 4      7-4=> 3    
     i- prevSmaller[i]     nextSmaller[i]- i
               
               ->> 4*3 = 12 elements

               12* arr[i]= (12)*3 => 36 will add it in ans...

    *** Remember to handle base case ->> for either of one use <= and use only <
      for other while poping out elements from stack       

*/


// TC= O(2*N + 2*N + N) -> O(5* N)
// SC= O(4* N)

class Solution{
 public:
    #define MOD 1000000007
    
    vector<int> find_nextSmaller(vector<int> &arr)
    {
        int n= arr.size();
        stack<int> st;

        vector<int> nse(n, n);

        // Traverse from end to find next smaller element
        // Pop out element from st until it is >= curr element
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                nse[i]= st.top();
            }
            // else nse[i]= n;

            st.push(i);
        }
    return nse;
    }



    vector<int> find_prevSmaller(vector<int> &arr)
    {
        int n= arr.size();
        vector<int> pse(n, -1);

         stack<int> st;  // to store index
        
    // Traverse from start to find out prev smaller element pop out all elements that are greater than curr element..
         for(int i=0; i<n; i++)
         {
            while(!st.empty() && arr[st.top()] > arr[i]) 
            {
                st.pop();
            }

            if(!st.empty())
            {
                pse[i]= st.top();
            }
            // else pse[i]= -1

             st.push(i);
         }
       return pse;  
    }



    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        
        vector<int> prevSmaller = find_prevSmaller(arr);
        vector<int> nextSmaller = find_nextSmaller(arr);

        long long sum= 0;
        for(int i=0; i<n; i++)
        {        
            long long leftCnt= i - prevSmaller[i];
            long long rightCnt= nextSmaller[i] - i;
            
            sum= (sum + (((leftCnt* rightCnt) % MOD)* arr[i]) % MOD) % MOD;
        }

    return int(sum);
    } 
};








// Brute Force Approach -> Generate all subarrays..
// TC= O(N^2)

/*

class Solution {
public:
    #define MOD 1000000007
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        
        long long sum= 0;
        for(int i=0; i<n; i++)
        {
            int mini= INT_MAX;
            for(int j= i; j<n; j++)
            {
                mini= min(mini, arr[j]);
                sum+= mini % MOD;
            }
        }
       return sum;
    }
};

*/
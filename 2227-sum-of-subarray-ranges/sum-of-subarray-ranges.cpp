// Similar QUES ->>>  (Sum of Subarray Minimums)


// Approach 2 -> Optimized stack..

// Range= (Total sum of subarray MAXIMUM)- (Total sum of subarray MINIMUM)

// TC= finding Subarray Maximum + finding subarray Minimum
// O(5* N) + O(5* N) =>> O(10* N)


class Solution {
public:
   // **** First find subarray Minimum ****
   
   // TC= O(2*N)
   vector<int> find_prevSmaller(vector<int> &arr)
   {
        int n= arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        
        // Traverse from start... pop out until it is greater than curr element
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
            // else pse[i]= -1;

           st.push(i); 
        }
      return pse;  
   }


    // TC= O(2* N)
    vector<int> find_nextSmaller(vector<int> &arr)
    {
        int n= arr.size();
        vector<int> nge(n, n);
        stack<int> st;
       
        // Traverse from end... and pop out until it is greater equal than curr element
        for(int i= n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                nge[i]= st.top();
            }
            // else nge[i]= n;

            st.push(i);
        }
      return nge;  
    }


    long long subarrayMinimum(vector<int> &arr)
    {
        int n= arr.size();
         vector<int> pse=  find_prevSmaller(arr);
         vector<int> nse=  find_nextSmaller(arr);
        
        long long ans= 0;
         for(int i=0; i<n; i++)
         {
            long long leftCnt= i - pse[i];
            long long rightCnt= nse[i] - i;
           
           ans= ans+ (leftCnt* rightCnt)* arr[i];
         }
        return ans; 
    }
    


    
    // *****  Now find subarray Maximum *****
    
    // TC= O(2* N)
    vector<int> find_prevGreater(vector<int> &arr)
    {
         int n= arr.size();
         vector<int> pge(n,-1);
         stack<int> st;
        
        // Traverse from start.. pop out until it is smaller than curr element
         for(int i=0; i<n; i++)
         {
            while(!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                pge[i]= st.top();
            }
            // else pge[i]= -1;

            st.push(i);
         }
      return pge;
    }


    // TC= O(2*N)
    vector<int> find_nextGreater(vector<int> &arr)
    {
        int n= arr.size();
        vector<int> nge(n, n);
        stack<int> st;  // to store index
       
       // Traverse from end.. pop out all elements until it is <= curr element
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                nge[i]= st.top();
            }
            // else nge[i]= n;

          st.push(i);  
        }
     return nge;
    }
   

    long long subarrayMaximum(vector<int> &arr)
    {
        int n= arr.size();
         vector<int> pge= find_prevGreater(arr);
         vector<int> nge= find_nextGreater(arr);
         
         long long ans= 0;
         for(int i=0; i<n; i++)
         {
            long long leftCnt= i - pge[i];
            long long rightCnt= nge[i]- i;

            ans= ans+ (leftCnt* rightCnt)* arr[i];              
         }
        return ans;
    }


 // Range ->> Total sum of Subarray Maximums - Total sum of Subarray Minimums

    long long subArrayRanges(vector<int>& arr) {
          return subarrayMaximum(arr)- subarrayMinimum(arr);
    }
};









// Brute Force Approach -> Generate all subarrays..
// TC= O(N^2)

/*

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n= nums.size();
        
        long long sum= 0;
        for(int i=0; i<n; i++)
        {
            int maxi= INT_MIN;
            int mini= INT_MAX;

            for(int j=i; j<n; j++)
            {
                maxi= max(maxi, nums[j]);
                mini= min(mini, nums[j]);

                sum+= (maxi-mini);
            }
        }
       return sum;
    }
};

*/
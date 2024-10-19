// Approach 1 -> Traverse from right and find store the idx of greatest element on right side
// TC= O(N)

class Solution{
 public:
     int maximumSwap(int nums)
     {
        string str= to_string(nums);
        int n= str.length();
        
        // to store the index of greatest element on right side
        vector<int> vec(n);
        vec[n-1]= n-1;

        for(int i=n-2; i>=0; i--)
        {
            // Store prev stored index in vec[i] 
            if(str[i] <= str[vec[i+1]])
            {
                vec[i]= vec[i+1];
            }

            // else the element itself is greatest ...
            else
            {
                vec[i]= i;
            }
        }
        
        // Now do only 1 swap... if str[i] < str[vec[i]]
        for(int i=0; i<n; i++)
        {
            if(str[i] < str[vec[i]])
            {
               swap(str[i],str[vec[i]]); 
               break;
            }
        }
    
    // convert string back to integer...
    return stoi(str);    
   }     
};
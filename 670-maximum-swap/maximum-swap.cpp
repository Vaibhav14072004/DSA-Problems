// Approach 2 (Optimized) -> 

// Take a vec of size- 9 to store the rightmost index of each char of string ..
// For each char, traverse the vec of size- 9 from right each time, to swap with greatest element on its right

// TC= O(N* 10) ->> O(N)
// SC= O(10) ->> O(1)

class Solution{
public: 
     int maximumSwap(int nums)
     {
        string str= to_string(nums);
        int n= str.length();  
        
        // to store the index of each char of string
        vector<int> vec(10,-1);
        for(int i=0; i<n; i++)
        {
            vec[str[i]- '0']= i;
        }

        for(int i=0; i<n; i++)
        {
            int digit= str[i]-'0';
            for(int j=9; j> digit; j--)
            {
                if(vec[j] > i)
                {
                    swap(str[i],str[vec[j]]);
                    return stoi(str);
                }
            }
        }
    
    return nums;
    }
};






// Approach 1 -> Traverse from right and find store the idx of greatest element on right side
// TC= O(N)

/*

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
            // if we have not taken equal(=) sign then righmost greatest index will get replaced by leftmost index...
            // For ex- 1993   output-  9913  but if we not take = sign then wrong out- 9193 which is incorrect

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

*/
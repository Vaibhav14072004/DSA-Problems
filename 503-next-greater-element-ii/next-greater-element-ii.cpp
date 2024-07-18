// Optimal Approach -> Using stack..
// TC= O(2* 2N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        stack<int> st;
        vector<int> nge(n,-1);
       
       // Assume nums to be size of 2n... circular array..
        for(int i=2*n-1; i>= 0; i--)
        {
            // pop out elements till st.top() <= nums[i%n]
            while(!st.empty() && st.top() <= nums[i%n])
            {
                st.pop();
            }

            // we would store ans only when i < n
            if(i< n)
            {
                if(!st.empty())
                {
                    nge[i]= st.top();
                }

                // else nge[i]= -1; ... no need as we have already initialize with -1
            }
        
        st.push(nums[i % n]);
        }

      return nge;  
    }
};






// Brute Force Approach 
// TC= O(N^2)

/*

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n= arr.size();
        vector<int> nge(n,-1);

        for(int i=0; i<n; i++)
        {
            // j loop will run till (i+ n)
            for(int j= i+1; j<i+n; j++)
            {
                if(arr[j % n] > arr[i])
                {
                    nge[i]= arr[j % n];
                    break;
                }
            }
        }
    return nge;
    }
};

*/
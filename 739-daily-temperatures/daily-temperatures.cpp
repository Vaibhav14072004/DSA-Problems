// Ques ->> Next greater element

// Approach 1 -> Using only one parameter in stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n= arr.size();
        vector<int> nge(n,0);

        // for storing index of next greater element...
        stack<int> st;

        // Traverse array from end...
        for(int i=n-1; i>=0; i--)
        {
      // pop out elements until it is smaller than curr.. bcoz we have to find next greater temp
            while(!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
           
           // (Next Greater element Index- Curr index) will give no of elements <= curr element
            if(!st.empty())
            {
                nge[i]= st.top()- i;
            }

            // else nge[i]= 0;  ->> No need, as we have already initialized with 0

            st.push(i);
         }
     return nge;
    }
};





// Approach 2 -> Using pair in stack
// TC= O(2*N)

/*

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n= arr.size();
        vector<int> nge(n,0);
        
        // {element, index}
        stack<pair<int,int>> st;
        
        // Traverse from end...
        for(int i= n-1; i>= 0; i--)
        {
            while(!st.empty() && st.top().first <= arr[i])
            {
                st.pop();
            }
            
         // (Curr Index- nextGreaterElement index) will give no of days to get warmer day.. 
            if(!st.empty())
            {
                nge[i]= st.top().second - i;
            }

         // else nge[i]= 0; ->> No need to write this as already initialized with 0

         st.push({arr[i], i});
        }
        return nge;
    }
};

*/


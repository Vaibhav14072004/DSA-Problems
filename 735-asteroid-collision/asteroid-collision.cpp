// Ques of Greedy Approach
// TC= O(2* N)

// Approach 1 -> Using vector.. No need to do reverse

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n= arr.size();
        
       vector<int> ans;
       for(int i=0; i<n; i++)
       {
         // directly push if arr[i] is +ve
         if(arr[i] > 0)
         {
             ans.push_back(arr[i]); 
         }
        
    // if arr[i] is -ve (moving in opp dir) .. Then 2 case arise (st.top() < 0 or st.top() > 0)
        else
        {
            // 1. st.top() is +ve
            while(!ans.empty() && ans.back() > 0 && abs(arr[i]) > ans.back())
            {
                 ans.pop_back();
            }

            // 2. if st.top() is -ve
            if(ans.empty() || ans.back() < 0)
            {
                ans.push_back(arr[i]);
            }

            // 1. if st.top() is +ve
            else if(!ans.empty() && ans.back() > 0 && ans.back()== abs(arr[i]))
            {
                ans.pop_back();
            }
            
        }
    }
        return ans;
    }
};






// Approach 2 -> Using stack ... we have to do reverse
/*

class Solution{
  public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n= arr.size();
        
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            // if arr[i] is +ve .. directly push into stack
            if(arr[i] > 0)
            {
               st.push(arr[i]);
            }
           
           // if arr[i] is -ve (Moving in opp direction)
            else
            {
                // Case1 -> st.top() is +ve,, pop out until st.top() < arr[i]
                while(!st.empty() &&  st.top() > 0 && st.top() < abs(arr[i]))
                {
                    st.pop();
                }

                // Case 2 -> st.top() is -ve, directly push arr[i] in stack
                if(st.empty() || st.top() < 0)
                {
                    st.push(arr[i]);
                }
                
                // Case 1 -> st.top() is +ve , and we got equal opposite value..
                else if(!st.empty() && st.top() > 0 && st.top()== abs(arr[i]))
                {
                    st.pop();
                }
            }
        }

        // store the result in ans vector and reverse it..
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }      
};

*/
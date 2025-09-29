// Computing array of next smaller and prev smaller elements..
// Then For each element, check maxArea= max(maxArea, (nextSmaller - prevSmaller - 1))

// TC= O(3*N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n= heights.size();
        vector<int> prevSmaller(n,-1);
        vector<int> nextSmaller(n,n);

        stack<int> st;
        st.push(-1);

        // Computing prev smaller element for all elements..
        for(int i=0; i<n; i++)
        {
            // pop out elements from stack until it is st.top() is greater or equal
            while(st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
           prevSmaller[i]= st.top();
           st.push(i); 
        }
        
        stack<int> stck;
        stck.push(n);

         // Finding next smaller element for all elements..
        for(int i=n-1; i>=0; i--)
        {
            while(stck.top() != n && heights[stck.top()] >= heights[i])
            {
                stck.pop();
            }
          nextSmaller[i]= stck.top();
          stck.push(i);
        }

        int maxArea= 0;
        for(int i=0; i<n; i++)
        {
            int next= nextSmaller[i];
            int prev= prevSmaller[i];
            maxArea= max(maxArea, (next-prev-1)* (heights[i]));
        }
    return maxArea;
    }
};




/*---- CODE for prev smaller -----
 
    stack<int> st;
    for(int i=0; i<n; i++)
    {
        while(heights[st.top()] >= heights[i]){
            st.pop();
        }

       if(st.empty()) nextSmaller[i]= -1;
       else nextSamller[i]= st.top();

       st.push(i); 
    }

  ---- CODE for next smaller ------

     stack<int> st;
     for(int i=n-1; i>=0; i--)
     {
        while(heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()) nextSmaller[i]= n;
        else nextSmaller[i]= st.top();

        st.push(i);
     }

--------------------------------------

---- OTHER WAY for next smaller ----

stack<int> st;
st.push(n);

vector<int> nextSmaller(n,n);

for(int i=n-1; i>=0; i--)
{
    while(st.top() != n && heights[st.top()] >= st.top()){
        st.pop();
    }
   
    nextSmaller[i]= st.top();
    st.push(i);
}

*/
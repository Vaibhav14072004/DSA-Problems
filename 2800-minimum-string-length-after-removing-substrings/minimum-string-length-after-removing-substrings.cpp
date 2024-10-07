// Approach 1 -> Using Stack
// TC= O(N)
// SC= O(N)

class Solution {
public:
    int minLength(string str){
        int n= str.length();
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            if(!st.empty() && str[i]== 'B' && st.top()== 'A')
            {
                st.pop();
            }
            else if(!st.empty() && str[i]== 'D' && st.top()== 'C')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
        return st.size();
    }
};
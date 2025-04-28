// Approach 1 -> While loop
// TC= O(N)

class Solution {
public:
    string reverseWords(string str) {
        int n= str.length();
        stack<string> st;

        int i=0;
        string temp= "";
        while(i < n)
        {
            // first skip leading spaces..
            while(i < n && str[i]== ' ')
            {
                i++;
            }

            while(i<n && str[i] != ' ')
            {
                temp+= str[i];
                i++;
            }
            
            if(!temp.empty())
            {
                st.push(temp);
            }

            temp= "";
            i++;
        }

        string ans= "";
        while(!st.empty())
        {
            ans+= st.top();
            st.pop();
            
            // to give one space between each word
            if(!st.empty())
            {
                ans+= ' ';
            }
        }
        return ans;
    }
};
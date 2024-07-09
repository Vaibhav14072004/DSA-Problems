// 

class Solution {
public:
    string reverseParentheses(string s){
        int n= s.length();

        stack<char> st;
        for(int i=0; i<n; i++)
        {
            // if closing bracket found, then we need to reverse chars in stack until opening bracket found..
            if(s[i] == ')')
            {
            string temp= "";
            while(st.size() > 0 && st.top() != '(')
            {
                temp+= st.top();
                st.pop();
            }
            
            // to pop out '(' ....
            if(!st.empty())
            {
                st.pop();  
            }
            
            for(int j=0; j< temp.length(); j++)
            {
                st.push(temp[j]);
            }
        }
       
       // else store this char directly in stack..
        else
        {
            st.push(s[i]);
        }
     }
        
        // pop out elements from stack and get in ans in revere order..
        string ans= "";
        while(!st.empty())
        {
            ans= st.top()+ ans;
            st.pop();
        }
       return ans; 
    }
};
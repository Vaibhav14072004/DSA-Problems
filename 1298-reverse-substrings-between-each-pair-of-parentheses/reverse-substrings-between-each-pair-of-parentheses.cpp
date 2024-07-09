// Approach 2 -> Using reverse STL function...
// Changing the original string.. and storing index in stack. 

class Solution {
public:
    string reverseParentheses(string s){
        int n= s.length();
        
        // stack to store index of opening '('
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            // reverse the chars of stack until we found '('
            if(s[i]== '(')
            {
                st.push(i);
            }
            
            // reverse the string from recent '(' to curr ')' bracket..
            else if(s[i]== ')')
            {
                int recentOpeningBracket= st.top();
                st.pop();

                reverse(s.begin()+ recentOpeningBracket+ 1, s.begin() + i);
            }
        }

        // now given string s will contain our ans ... just remove opening closing bracket
        string ans= "";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]== ')' || s[i]== '('){
                continue;
            }
            ans= ans+ s[i];
        }
    return ans;
    }
};  





// Approach 1 ->> Without using reverse stl function
// Tc= O(N)   Sc= O(N)

/*

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

*/
// Approach -> Using stack
// TC=O(N)

class Solution {
public:
    char solve(char operation, vector<char> &vec)
    {
        // Case 1 ->> Not equal (!)
        if(operation== '!')
        {
            if(vec.back()== 't')
            {
                return 'f';
            }
            else
            {
                return 't';
            }
        }
        
        // Case 2 ->> AND (&)
        else if(operation== '&')
        {
            for(int i=0; i<vec.size(); i++)
            {
                if(vec[i]== 'f')
                {
                    return 'f';
                }
            }
            return 't';
        }
        
        // Case 3 ->> OR (|)
        else if(operation== '|')
        {
            for(int i=0; i<vec.size(); i++)
            {
                if(vec[i] == 't')
                {
                    return 't';
                }
            }
         return 'f';
        }

        // this line will never be reached,this is just written for return type
        return 'f';
    }


    bool parseBoolExpr(string str) {
        int n= str.length();
        
        stack<char> st;
        for(int i=0; i<n; i++)
        {
            // pop elements from stack until we find '(' and do required operation..
            if(str[i]== ')')
            {
                vector<char> vec;
                while(!st.empty() && st.top() != '(')
                {
                    vec.push_back(st.top());
                    st.pop();
                }
                
                // to pop out '('
                st.pop();
    
                // now apply operation...
                char operation;
                if(!st.empty())
                {
                    operation= st.top();
                }
            
                st.pop();
                char output= solve(operation, vec);
                st.push(output);
            }

            else if(str[i] != ',')
            {
                st.push(str[i]);
            }
        }
       return st.top()== 't'; 
    }
};
// Approach 4 ->> Using stringstream
// TC= O()

class Solution{
  public:
    string reverseWords(string str) {
        int n= str.length();
        stringstream ss(str);
        string token= "";
        
        stack<string> st;
        while(ss >> token)
        {
            st.push(token);
        }
         
        string ans= "";
        while(!st.empty())
        {
            ans+= st.top();
            st.pop();
            ans+= " ";
        }

        // to remove the last extra " "
        ans.pop_back();
      return ans;  
    }
};










// Approach 2 -> Using for loops..
// TC= O(N)

/*

class Solution {
public:
    string reverseWords(string str) {
        int n= str.length();

        string temp= "";
        string ans= "";

        stack<string> st;
        for(int i=0; i<n; i++)
        {
            if(str[i]== ' ')
            {
                continue;
            }

            while(i < n && str[i] != ' ')
            {
                temp+= str[i];
                i++;
            }

          st.push(temp);
          temp= "";
        }
    
    while(!st.empty())
    {
       ans+= st.top();
       st.pop();
       if(!st.empty())
       {
          ans+= ' ';
       }
    }
    return ans;
  }
};

*/







// Approach 1 -> While loop
// TC= O(N)

/*

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

*/
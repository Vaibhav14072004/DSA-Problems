// Approach 1 -> Using DFS 
// TC= O(N)

class Solution{
public:
    string add(string s, int a){
        
        // add a to odd indexies only..
        for(int i=1; i<s.length(); i+=2)
        {
            // s[i]- '0' converts string to integer... +'0' converts int to str
            s[i]= (((s[i]-'0') + a) % 10) + '0';
        }
        return s;
    }


    string rotate(string s, int b){
        int n= s.length();
        s= s.substr(n-b)+ s.substr(0,n-b);
        return s;
    }


    void dfs(string s, string &ans, unordered_set<string> &st, int a, int b){

        // if this curr node is already present in st..
        if(st.find(s) != st.end()) {
           return;
        }

        st.insert(s);
        
         // ans should contain lexographically smallest string..
         if(s < ans){
            ans= s;
         }
        
        string added= add(s,a);
        dfs(added,ans,st,a,b);

        string rotated= rotate(s,b);
        dfs(rotated,ans,st,a,b);
    }


    string findLexSmallestString(string s, int a, int b) {
        int n= s.length();

       // set to keep track whether this node has been visited before.. 
       unordered_set<string> st;
       string ans= s;

       dfs(s,ans,st,a,b);
       return ans;
    }
};









// Approach 1 -> USing BFS -> Beats 68.03 % users in C++

/*

class Solution {
public:
    string add(string s, int a)
    {
        int n= s.length();
        for(int i=0; i<n; i++)
        {
            // s[i]-'0' converts str to integer.... + '0' converts integer to string..
            if(i % 2 == 1)
            {
                s[i]= (((s[i]-'0')+ a) % 10) + '0';
            }
        }
     return s;
    }


    string rotate(string s,int b)
    {
        int n= s.length();
        string temp= "";
        temp= s.substr(n-b) + s.substr(0,n-b);
        return temp;    
    }


    string findLexSmallestString(string s, int a, int b) {
        int n= s.length();
     
     // to keep track whether this string has been formed earlier.. 
      unordered_set<string> st;
      queue<string> q;
      
      string ans= s;
      q.push(s);
      st.insert(s);

      while(!q.empty())
      {
          string curr= q.front();
          q.pop();
        
        // update the lexographically smallest string..
           if(curr < ans)
           {
               ans= curr;
           }

        // Operation 1. Add a to string s...
          string temp= add(curr,a);

          // if this string has NOT been found earlier...
          if(st.find(temp) == st.end())
          {
             q.push(temp);
             st.insert(temp);
          }

          // Operation 2. Rotate string by b
          string temp2= rotate(curr,b);
        
        // if this state has NOT been found earlier..
          if(st.find(temp2) == st.end())
          {
              st.insert(temp2);
              q.push(temp2);
          }
      }

    return ans;
    }
};

*/
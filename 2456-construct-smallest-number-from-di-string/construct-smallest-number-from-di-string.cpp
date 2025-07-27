// Approach 2 ->> Optimized Approach using Stack
// TC= O(N)

class Solution{
  public:
    string smallestNumber(string pattern) {
        int n= pattern.size();
         string ans= "";

         stack<int> st;
         int cnt= 1;
         for(int i=0; i<=n; i++)
         {
            st.push(cnt);
             cnt++;
             if(i== n || pattern[i]== 'I')
             {
                while(!st.empty())
                {
                    ans+= (st.top()+ '0');
                    st.pop();
                }
            }
         }
       return ans;  
    }
};





// Approach 1 -> Brute Force Approach
// Generating all permutations... and checking for it 

// TC= O(N* (N+1)!)

/*

class Solution {
public:
    bool valid(string &pattern,string &temp)
    {
        for(int i=0; i<pattern.size(); i++)
        {
            if(pattern[i]== 'I' && temp[i] > temp[i+1])
            {
                return false;
            }
            else if(pattern[i]== 'D' && temp[i] < temp[i+1])
            {
                return false;
            }
        }
      return true;  
    }
    
    string smallestNumber(string pattern) {
        int n= pattern.size();
        string temp= "";

        // temp-> 1 2 3 4 5 6 7 8 9
        for(int i=1; i<=n+1; i++){
            temp+= i+ '0';
        }

        while(!valid(pattern,temp)){
            next_permutation(temp.begin(),temp.end());
        }

    return temp;  
    }
};

*/
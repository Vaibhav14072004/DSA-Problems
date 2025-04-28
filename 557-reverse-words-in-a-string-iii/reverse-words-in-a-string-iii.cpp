// Asked Today on 28/4/2025 in Zopsmart OA in CL1 (JIIT Noida)

// Approach 2 ->> Using while loop
// TC= O(N)

class Solution{
public:
    string reverseWords(string str) {
        int n= str.length();
        string ans= "";
        string temp= "";

        int i=0;
        while(i < n)
        {
            while(i< n && str[i]== ' '){
                i++;
            }

            while(i< n && str[i] != ' ')
            {
                temp= str[i]+ temp;
                i++; 
            }

            ans+= temp;
            ans+= ' ';
            temp= "";
            i++;
        }
        
        // to remove the last space..
        ans.pop_back();
        return ans;
    }
};








// Approach 1 -> Using for loop
// TC= O(N)

/*

class Solution {
public:
    string reverseWords(string str) {
        int n= str.length();

        string ans= "";
        for(int i=0; i<n; i++)
        {
            if(str[i]== ' '){
                continue;
            }

            string temp= "";
            while(i< n && str[i] != ' ')
            {
                temp= str[i]+ temp;
                i++;
            }

        ans+= temp;
        ans+= ' ';
        }
        
        // to remove space from end
        ans.pop_back();
      return ans;  
    }
};

*/
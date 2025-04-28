// Asked Today on 28/4/2025 in Zopsmart OA in CL1 (JIIT Noida)
// TC= O(N)

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
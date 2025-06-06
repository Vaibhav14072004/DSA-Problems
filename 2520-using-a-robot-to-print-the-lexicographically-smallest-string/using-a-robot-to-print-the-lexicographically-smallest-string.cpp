// TC= O(N)

class Solution {
public:
    string robotWithString(string str) {
        int n= str.length();
        
        vector<char> rightSmaller(n);
        rightSmaller[n-1]= str[n-1];

        for(int i=n-2; i>=0; i--)
        {
            rightSmaller[i]= min(str[i],rightSmaller[i+1]);
        }

        string t= "";
        string page= "";

        int i= 0;
        while(i < n)
        {
            t+= str[i];
            i++;
            
            char minChar= str[i];
            if(i+1 < n)
            {
                minChar= min(minChar,rightSmaller[i+1]);
            }

            while(!t.empty() && t.back() <= minChar)
            {
                page+= t.back();
                t.pop_back();
            }
        }

        // if t does NOT become empty...
        while(!t.empty())
        {
            page+= t.back();
            t.pop_back();
        }
     return page;   
    }
};
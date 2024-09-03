// TC= O(N) + O(K* N) ->> O(N)

class Solution {
public:
    int getLucky(string s, int k) {
        string temp= "";

        for(char c: s)
        {
            temp+= to_string(c-'a' + 1);
        }
        
        while(k--)
        {
            int sum= 0;
            for(char ch: temp)
            {
                sum+= ch-'0';
            }
           temp= to_string(sum); 
        }

     return stoi(temp);   
    }
};
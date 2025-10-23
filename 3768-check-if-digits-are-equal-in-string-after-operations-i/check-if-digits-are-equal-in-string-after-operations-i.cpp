// TC= O(N^2)

class Solution {
public:
    bool hasSameDigits(string str) {
        int n= str.length();
        
        while(str.size() > 2)
        {
            string temp= "";
            for(int i=0; i<str.length()-1; i++)
            {
                int a= str[i]-'0';
                int b= str[i+1]-'0';
                temp+= (a+b) % 10;
            }
          str= temp;  
        }
    return str[0]== str[1];
    }
};
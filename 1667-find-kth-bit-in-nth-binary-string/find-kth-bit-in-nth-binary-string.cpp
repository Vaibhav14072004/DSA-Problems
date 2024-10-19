/* BIT MANIPULATION =>> To check if i'th bit is SET or NOT

1. Using left shift operator (<<)

   if(n & (1<< i)) != 0  -->>> SET (1)
   if(n & (i << i) == 0  ->>> UNSET(0)

2. Using right shift operator (>>)

   if(n >> i & 1) == 1 ->>> SET(1)
   if(n >> i & 1) == 0 ->>> UNSET(0)
 
*/




// USing recursion...

class Solution {
public:
    string makeStr(int n)
    {
        // base case
        if(n== 1) return "0";
        
        // recursion...
        string str1= makeStr(n-1);
       
       // inverting the string str1..
        string str2= "";
        for(int i=0; i<str1.size(); i++)
        {
            if(str1[i]== '0') 
               str2+= "1";

            else 
            str2+= "0";
        }

        reverse(str2.begin(), str2.end());
    
    return str1+ "1" + str2;
    }


    char findKthBit(int n, int k)
    {
        string ans= makeStr(n);

        // String are starting from s1 that is 1 based indexing.. but string are have 0 based indexing..
        return ans[k-1];
    }
};





// Without Recursion

/*

class Solution {
   public:
    string invert(string str)
    {
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]== '0') 
              str[i]= '1';

              else 
              str[i]= '0';
        }
        return str;
    }
    
    string reverse(string str)
    {
        int n= str.length();
        string temp= "";
        for(int i= n-1; i>=0; i--)
        {
            temp+= str[i];
        }
        return temp;
    }


    char findKthBit(int n, int k)
    { 
        string str1= "0";

        for(int i=1; i<=n; i++)
        {
            str1+= "1"+ reverse(invert(str1));
        }
    
    // str have 1 based indexing bcoz s1= "0"... but array have 0 based indexing.. 
    return str1[k-1];
    }
};

*/





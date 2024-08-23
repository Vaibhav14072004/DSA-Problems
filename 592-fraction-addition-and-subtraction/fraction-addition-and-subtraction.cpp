class Solution {
public:
    string fractionAddition(string str) {
        int n= str.length();
        
        int num= 0;
        int den= 1;
        
        int i= 0;
        while(i < n)
        {
            int currNum= 0;
            int currDen= 0;

            bool negativeSign= (str[i]== '-');

            if(str[i]== '+' || str[i]== '-')
            {
                i++;
            }

            // Ex- 10/4  ... first populate numeratr,, currNum= 10... 
            while(i < n && str[i] != '/')
            {
                int val= str[i]-'0';
                currNum= currNum*10 + val;
                i++;
            }

            i++; // to skip '/' 

            if(negativeSign)
            {
                currNum= - currNum;
            }
            
            // now populate curr denominator...
            while(i < n && str[i] != '+' && str[i] != '-')
            {
                int val= str[i]- '0';
                currDen= currDen*10 + val;
                i++;
            }

            // LCM of a/b + c/d =>> (a*d + b*c)/ (b*d)  

            num= currNum* den + currDen* num;
            den= den* currDen;
        }
      
      // Now find gcd of numerator and denominator...
      int GCD= abs(__gcd(num,den));

      num= num/GCD;
      den= den/GCD;
      
      string ans= to_string(num) + "/" + to_string(den);
     return ans;
    }
};
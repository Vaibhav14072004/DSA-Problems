// TC= O(denominator)

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        // base cases
         if(numerator== 0) return "0";

         string ans= "";
         if((1LL* numerator* denominator) < 0){
            ans+= "-";
         }

         long long num= labs(numerator);
         long long den= labs(denominator);

         long long div= num/den ;
         ans+= to_string(div);

         long long rem= num % den;
         if(rem== 0)
         {
            return ans;
         }

         ans+= ".";
         
         // map is taken so that we can know the exact positon
         // where we can put opening bracket, when it is repeating
         unordered_map<long long,int> mp;

         while(rem != 0)
         {
            // if repeating starts...
            if(mp.count(rem))
            {
                // put opening bracket
                ans.insert(mp[rem], "(");
                ans+= ")";
                break;
            }

            mp[rem]= ans.length();
            rem*= 10;
            int digit= rem/den;
            ans+= to_string(digit);
             rem= rem % den;
         }
    return ans;
    }
};
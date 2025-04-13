/*
   There can be EVEN -> (n+1)/2   ODD= n/2 places

   For every EVEN place -> we can put even numbers from 0 to 9
     that is [0,2,4,6,8] ->> 5 possiblity for even place

    For every ODD place -> we can put all prime numbers from 0 to 9
     that is [2,3,5,7] ->> 4 possibilty for odd place

    Ex- n= 5
     There are (n+1/2) -> 3 EVEN Place
     There are (n/2) -> 2 ODD place

 Possiblity   5     4       5     4       5
             ___    ___    ___    ___     ___  


    Total valid numbers possible -> 5*4*5*4*5  
        => (5)^3  * (4)^2
        => (5)^ No of even places  *  (4)^ No of odd places     

        =>  (5)^ (n+1/2)  * (4)^ (n/2)

        => pow(5, (n+1/2))* pow(4, (n/2)) 
    
    Finding that high power can give TLE so use Binary Exponentiation for finding power
    
    TC of finiding pow(a,b) using Binary Exponentiation is
      O[log (b)]
*/

// TC= O(log(N+1/2)) * O(log(n/2)) ->> O(log N)


class Solution {
public:
  const int MOD= 1e9+7;

   long long findPow(long long a, long long b)
   {
       // base case..
       if(b== 0){
          return 1;
       }

       long long half= findPow(a,b/2);
       long long result= (half* half) % MOD;
       
       // if b is odd
       if(b % 2 == 1)
       {
          result= (result* a) % MOD;
       }
     return result;  
   }


    int countGoodNumbers(long long n) {
        long long evenPlaces= (n+1)/2;
        long long oddPlaces= n/2;
        
        // multily by 1LL to typecast it in long long
        long long ans= (1LL* findPow(5, evenPlaces) * findPow(4, oddPlaces)) % MOD;
        return (int) ans;
    }
};
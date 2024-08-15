// **** Sieve of Eratosthenes ****
// mark all multiples of 2, 3, 5 .. to N ..as 0 as they are NOT prime


// Approach 1 -> Without optimization...
// TC= O(N* log N) + O(N) ->> O(N log N)


class Solution{
 public:
    int countPrimes(int n)
    {
         vector<int> isPrime(n, 1);

         for(int i=2; i<n; i++)
         {
             if(isPrime[i]== 1)
             {
                // this loop will run n/i times... TC= O(log n)
                for(int j=2*i; j<n; j+=i)
                {
                    isPrime[j]= 0;
                }
             }
         }

         int cnt= 0;
         for(int i=2; i<n; i++)
         {
            if(isPrime[i]== 1)
            {
                cnt++;
            }
         }
       return cnt;  
    }
};









/* If we want to find all prime numbers till N ... (N is included)

class Solution {
public:
    int countPrimes(int n)
    {
         vector<int> isPrime(n+1, 1);

         for(int i=2; i<=n; i++)
         {
            if(isPrime[i]== 1)
            {
                // this loop will run n/i times... TC= O(log n)
               for(int j= 2*i; j<=n; j+= i)
               {
                   isPrime[j]= 0;
                }
            }
         }
         
         int cnt= 0;
         for(int i=2; i<= n; i++)
         {
             if(isPrime[i]== 1)
             {
                cnt++;
             }
         }  
       return cnt;   
    }
};

*/
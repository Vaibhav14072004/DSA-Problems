// Approach 1 -> Sieve of Eratosthenes
// TC= O(N log log N) + O(right-left) + O(N)

class Solution {
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> isPrime(right+1, true);
        isPrime[0]= false;
        isPrime[1]= false;
        
        // Sieve of Eratosthenes -> TC= O[N* (log log N)]
        for(int i=2; i*i <= right; i++)
        {
            if(isPrime[i]== true)
            {
                for(int j=2; i*j <= right; j++)
                {
                    isPrime[i*j]= false;
                }
            }
        }
        
        // 0,1 are NOT primes
        vector<int> prime;
        for(int i=left; i<=right; i++)
        {
            if(isPrime[i]){
                prime.push_back(i);
            }
        }

        if(prime.size() < 2)
        {
            return {-1,-1};
        }
        
        int minDiff= INT_MAX;
        int a= -1, b= -1;

        for(int i=1; i<prime.size(); i++)
        {
            if(prime[i]-prime[i-1] < minDiff)
            {
                minDiff= prime[i]-prime[i-1];
                a= prime[i-1];
                b= prime[i];
            }
    
            // smallest diff that can be obtained will either 1 or 2, so directly return
            if(minDiff <= 2)
            {
                break;
            }   
        }
    return {a,b};
    }
};
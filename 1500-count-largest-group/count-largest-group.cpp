// Approach 2 -> Using separate function to find sum using divide and modulus
// TC= O(N* log(D))

class Solution{
 public:
    int digitSum(int number)
    {
        int sum= 0;
        while(number != 0)
        {
            sum+= number % 10;
            number= number/10;
        }
      return sum;  
    }

    int countLargestGroup(int n)
    { 
        // max n can go upto 10^4 -> max sum of digits of 9999 can be 36
        vector<int> freq(37,0);
         
        int maxSize= 0, cnt= 0;
        for(int i=1; i<=n; i++)
        {
            int sum= digitSum(i);
            freq[sum]++;

            if(freq[sum] > maxSize)
            {
                maxSize= freq[sum];
                cnt= 1;
            }
            else if(freq[sum]== maxSize)
            {
                cnt++;
            }
        }
     return cnt;   
    }
};





// Approach 1 -> Iterating on entire digits to find sum
// TC= O(N*d) + O(N)

/*

class Solution {
public:
    int countLargestGroup(int n) {
        int maxSize= 0;
        
        // given that n= 10^4, maximum sum of 9999 can be 36
        // vector<int> vec(37,0);

        unordered_map<int,int> mp;
        for(int i=1; i<=n; i++)
        {
            string temp= to_string(i);
            int sum= 0;
            for(auto it: temp){
                sum+= (it-'0');
            }

            mp[sum]++;
            if(mp[sum] > maxSize)
            {
                maxSize= mp[sum];
            }
        }
        
        int cnt= 0;
        for(auto it: mp)
        {
            if(it.second== maxSize)
            {
                cnt++;
            }
        }

        return cnt;
    }
};

*/
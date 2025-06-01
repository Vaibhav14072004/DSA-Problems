class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        //child1
        int minCh1 = max(0, n - 2*limit);
        int maxCh1 = min(n, limit);

        for(int i = minCh1; i <= maxCh1; i++) { //fixing child1 assignment of candies

            int N = n-i; //for ch2 and ch3

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};







// Approach 2 -> Using 2 for loops
// TC= O(N^2)

/*

class Solution{
public:
    long long distributeCandies(int n, int limit)
    {
        int ways= 0;
       for(int c1= 0; c1<= min(n,limit); c1++)
       {
           for(int c2= 0; c2 <= min(n-c1,limit); c2++)
           {
               int c3= n-c1-c2;
               if(c3 <= limit)
               {
                   ways++;
               }
           }
       }
     return ways;  
    }
};

*/





// Approach 1 -> Brute Force Approach -> Try every combination
// TC= O(limit ^ 3)

/*

class Solution {
public:
    int solve(int childCnt, int n, int limit)
    {
        // base case
        if(childCnt== 3)
        {
            if(n== 0){
                return 1;
            }
            return 0;
        }

        int ways= 0;
        for(int candy= 0; candy <= min(n,limit); candy++)
        {
            ways+= solve(childCnt+1, n-candy, limit);
        }
      return ways;  
    }

    long long distributeCandies(int n, int limit) {
        return solve(0,n,limit);
    }
};

*/
// Ques -> Sum of all divisors excluding no itself should be equal to no

// Approach 2 (Optimized)

// TC= O(sqrt(N))

/*

class Solution{
public:
    bool checkPerfectNumber(int num) {
        int sum= 0;
        
        // base case
        if(num <= 1){
            return false;
        }

        for(int i=1; i*i <= num; i++)
        {
             if(num % i == 0)
             {
                sum+= i;
                if((num/i) != i)
                {
                    sum+= (num/i);
                }
             }
        }

    // bcoz we have to NOT include sum of num itself... 
    return num== (sum-num);
    }
};

*/




// Approach 1 ->  TC= O(N)


class Solution {
public:
    bool checkPerfectNumber(int num) {

        // base case
        if(num <= 1)
        {
            return false;
        }

        int sum= 0;
       
       // loop will run till i < num bcoz we does need to include no itself
        for(int i=1; i<num; i++)
        {
            if(num % i == 0)
            {
               sum+= i;
            }
        }

      return sum== num;
    }
};

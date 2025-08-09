class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        for(int i=0; i<30; i++)
        {
            if(ans == n)
            {
                return true;
            }
            // if(ans<INT_MAX/2)
            ans = ans * 2;
            if(ans == n)
            {
                return true;
            }
            
        }
        return false;
        
    }
};




// TC= O(1)  SC= O(1)

/*

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
    
    // binary representation of n & binary representation of n-1 == 0
    // if n is multiple of 2
        return (n&(n-1))== 0;
    }
};

*/


// TC= O(log N)
// SC= O(1)

/*

class Solution{
public:
    bool isPowerOfTwo(int n){
       if(n<=0){
        return false;
       }
    
    long long int x= 1;
    while(x<n)
    {
     x= x*2;
    }

    if(x== n){
        return true;
    }
    return false;
}};

*/
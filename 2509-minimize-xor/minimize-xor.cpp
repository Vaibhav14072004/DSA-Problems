// TC= O{ceil(log 2 (N)) + 1} ->> log2 (N)
//  SC= O(1)

class Solution {
public:
    int minimizeXor(int num1, int num2)
    {
        // find no of set bits in num1
        // int setBits1= __builtin_popcount(num1);

        int currBits= 0;
        for(int i=0; i<32; i++)
        {
            if((num1 & (1<<i)) != 0)
            {
                currBits++;
            }
        }

        int reqBits= 0;
        for(int i=0; i<32; i++)
        {
            if((num2 & (1<<i)) != 0)
            {
                reqBits++;
            }
        }
        
        // if setBits1== setBits2, directly return num1 bcoz xor of num1 ^ num1 will be smallest
        int ans= num1;
        int bit= 0;

        // unset the (currBits-reqBits) no of bits, starting from lsb
        if(currBits > reqBits)
        {
           while(currBits > reqBits)
           {
               // if the curr bit is set, then unset the curr bit
               if((ans & (1<<bit)) != 0)
               {
                  ans= ans & ~(1<<bit);
                  currBits--;
               }
              bit++;
           }
        }

        // set the (reqBits-currBits) no of bits, starting from lsb
        else if(currBits < reqBits)
        {
            // if the curr bit is NOT set, then set it..
            while(currBits < reqBits)
            {
                if((ans & (1<< bit)) == 0)
                {
                    ans= ans | (1<<bit);
                    currBits++;  
                }
                bit++;
            }
        }
    return ans;
    }
};
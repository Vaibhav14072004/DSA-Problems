/*
**** ---- Bit Manipulations Operations  --- *****

1) To Check if the currBit is SET or NOT 
    
    if((num1 & (1<< currBit)) != 0) ->> curr bit is SET
    if((num1 & (1<< currBit)) == 0) ->> curr bit is UNSET (not set)

2) To SET the curr bit
   
   ans= ans | (1<<currBit)

3) To UNSET the curr bit
   
   ans= ans & ~(1<< currBit)

4) Count no of set bits
   
   __builtin_popcount(num)
   
*/



// Approach 2 ->> Set bits starting from MSB if currBit in nums1 is set, else set remaining bits from LSB

// TC= O(32)
// SC= O(1)

class Solution {
public:
    int minimizeXor(int num1, int num2)
    {
        // find no of set bits in num1
        // int reqBits=  __builtin_popcount(num1);
    
        int reqBits= 0;
        for(int i=0; i<32; i++)
        {
            if((num2 & (1<<i)) != 0)
            {
                reqBits++;
            }
        }
        
        int ans= 0;

        // Start from MSB, if the curr bit in nums1 is set, set it in ans also
        for(int i=31; i>=0 && reqBits > 0; i--)
        {
            if((num1 & (1<<i)) != 0)
            {
                ans= ans | (1<<i);
                reqBits--;
            }
        }

        // now set remaining bits of ans from LSB
        for(int i=0; i<= 31 && reqBits > 0; i++)
        {
            // if the curr bit is unset,then set the curr bit
            if((num1 & (1<<i)) == 0)
            {
                ans= ans | (1<<i);
                reqBits--;
            }
        }
    return ans;
    }
};



// Approach 1 ->> Set/Unset bits from LSB dependig upon currBits and reqBits

// TC= O{ceil(log 2 (N)) + 1} ->> log2 (N) -> O(32)
//  SC= O(1)

/*

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

*/
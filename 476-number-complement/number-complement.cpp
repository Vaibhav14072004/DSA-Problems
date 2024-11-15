// XOR of same numbers are 0
// XOR of diff numbers are 1

class Solution {
public:
    int findComplement(int num) 
    {
        int totalBits= 1 + log2(num);
        for(int i=0;i<totalBits; i++)
        {
            num= num ^ (1<<i);
        }
        return num;
    }
};
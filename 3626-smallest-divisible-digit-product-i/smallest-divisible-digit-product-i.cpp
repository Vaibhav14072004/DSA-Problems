class Solution {
public:
    int smallestNumber(int n, int t) {

        for(int i=n; ; i++)
            {
                int no= i;
                int product= 1;
                while(no > 0)
                    {
                        product*= no % 10;
                        no= no/10;
                    }
                if(product % t== 0)
                {
                    return i;
                }
            }
        return n;
    }
};
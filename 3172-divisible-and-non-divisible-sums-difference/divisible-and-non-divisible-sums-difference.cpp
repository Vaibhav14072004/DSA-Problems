class Solution {
public:
    int differenceOfSums(int n, int m)
     {
        int divisibleSum= 0, nonDivSum= 0;
        for(int i=1; i<=n; i++)
        {
            if(i % m== 0)
            {
                divisibleSum+= i;
            }
            else
            {
                nonDivSum+= i;
            }
        }
    return nonDivSum-divisibleSum;
    }
};
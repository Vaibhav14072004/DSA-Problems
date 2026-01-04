// TC= O(N* sqrt(N))

class Solution {
public:
    int sumDiv(int no)
     {
        int sum= 0, divCnt= 0;
        for(int i=1; i*i <= no; i++)
        {
            if(no % i == 0)
            {
                int otherNo= no/i;
                if(i == otherNo)
                {
                    divCnt++;
                    sum+= i;
                }
                else
                {
                    divCnt+= 2;
                    sum+= i;
                    sum+= otherNo;
                }
            }

            if(divCnt > 4) return 0;
        }
       return (divCnt== 4) ? sum: 0;
     }

    int sumFourDivisors(vector<int>& nums) {
        int n= nums.size();
        int sum= 0;
        for(int i=0; i<n; i++)
        {
            sum+= sumDiv(nums[i]);
        }
    return sum;    
    }
};
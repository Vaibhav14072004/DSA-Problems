class Solution {
public:
    int totalMoney(int n)
    {
        int ans= 0;
        int iterations= n/7;
        int rem= n % 7;
          
          int i=0;
          while(iterations--)
          {
             ans+= (28+ 7*i);
             i++;
          }
        
        int day= 1;
        while(rem--)
        {
            ans+= (i+day);
            day++;
        }
    return ans;
    }
};
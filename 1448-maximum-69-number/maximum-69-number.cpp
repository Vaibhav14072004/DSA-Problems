class Solution {
public:
    int maximum69Number (int num) {
        int n=0,max=0,count=0,dig;
        while(num>0)
        {
            dig=num%10;
            n=n*10+dig;
            num=num/10;
        }
        while(n>0)
        {
            dig=n%10;
            if(dig==6 && count==0)
            {
                max=max*10+9;
                count++;
            }
            else
            {
                max=max*10+dig;
            }
            n=n/10;
        }
        return max;
        
    }
};
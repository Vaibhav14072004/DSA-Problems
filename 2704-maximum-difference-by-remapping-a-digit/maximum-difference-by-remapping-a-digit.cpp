// TC= O(2*N)
// SC= O(1)

class Solution {
public:
    int minMaxDifference(int num) 
    {
        string str= to_string(num);
        int n= str.length();

        string maxi= "";
        char temp;
        bool flag= true;

        int i=0;
        while(i < n)
        {
            while(str[i]== '9'){
                maxi+= '9';
                i++;
                
                // to handle this testcase, if num= 00000
                if(i== n-1) break;
            }

            if(flag && str[i] != '9')
            {
                temp= str[i];
                flag= false;
            }

            if(str[i]== temp)
            {
                maxi+= '9';
            }
            else
            {
              maxi+= str[i];
            }
         i++;
       }
       
       // to convert string into integer 
        int maxNo= stoi(maxi);
        
        string mini= "";
        flag= true;
        char temp2;
        
        i=0;
        while(i < n)
        {
            while(str[i]== '0'){
                mini+= '0';
                i++;

                // to handle this testcase, if num= 00000
                if(i== n-1) break;
            }

            if(flag && str[i] != '0')
            {
                flag= false;
                temp2= str[i];
            }

            if(str[i]== temp2)
            {
                mini+= '0';
            }
            else
            {
                mini+= str[i];
            }
          i++;  
        }

        int minNo= stoi(mini);
     
    return maxNo-minNo;
    }
};
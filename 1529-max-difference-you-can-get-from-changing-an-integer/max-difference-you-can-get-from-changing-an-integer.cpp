// TC= O(2*N)

class Solution {
public:
    int maxDiff(int num) 
    {
        string str= to_string(num);
        int n= str.length();
        
        string maxi= "";
        char temp;
        bool first= true;
        
        int i=0; 
        while(i <n)
        {
           if(first && str[i] != '9')
           {
               temp= str[i];
               first= false;
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

        int maxNo= stoi(maxi);

        string mini= "";
        char temp2;
        i=0;
 
        // if the first digit is '1', skip all leading 1's, then all 0's
        // and then find any other non zero char.. to replace all its occurrence with 1
        if(str[0]== '1')
        {
           while(i < n && str[i]== '1')
           {
               mini+= '1';
               i++;
           }
           while(i < n && str[i]== '0')
           {
               mini+= '0';
               i++;
           }
           
           // find first non zero, non one element...
           for(int j=i; j<n; j++)
           {
               if(str[j] != '0' && str[j] != '1')
               {
                   temp2= str[j];
                   break;
               }
           }

            while(i < n)
            {
               if(str[i]== temp2)
               {
                  mini+= '0';
                  i++;
               }
               else
               {
                  mini+= str[i];
                  i++;
               }
           }
        }
        
        //  if first digit is not '1', then convert next digit into 1's 
        // (convert 0 to 1 also. as no leading zero accepted)

        else
        {
            char ch= str[0];
            for(int i=0; i<n; i++)
            {
                if(str[i]== ch)
                {
                    mini+= '1';
                }
                else
                {
                    mini+= str[i];
                }
            }
        }
        
     int minNo= stoi(mini);

    return maxNo-minNo;
    }
};
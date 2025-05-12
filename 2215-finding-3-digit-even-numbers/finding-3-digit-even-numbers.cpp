class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        //check every possible digit where the digit counr is 3 i.e from 100-999
        vector<int> ans;//store the valid digits from 100 to 999

        int currentarr[10]={0}; // to store current given array digits 
        for(int i=0; i<digits.size(); i++)
        {
            currentarr[digits[i]]++;
        }

        //now get the 3 digits of ebery even number ranging from 100 to 999 and store it in a temporary array
        int temp[10]={0};
        for(int j=100; j<=999; j+=2) 
        {
            int firstdigit=(j/100)%10;
            int seconddigit=(j/10)%10;
            int thirddigit=(j)%10;
            //store thise in a temporaray array
            temp[firstdigit]++;
            temp[seconddigit]++;
            temp[thirddigit]++;

            //noe comapre the digit array(currentarr) ele with these temp array elements if the curren arr elemets aregreater then store them in ans vector
            if(currentarr[firstdigit]>=temp[firstdigit] &&  currentarr[seconddigit]>=temp[seconddigit]  && currentarr[thirddigit]>=temp[thirddigit] )
            {
                ans.push_back(j); //that even number randing from 100 to 999
            }
        //now remove temp arr ele freq store to makeplace for storing next even num's digitds
            temp[firstdigit]--;
            temp[seconddigit]--;
            temp[thirddigit]--;        
        }
        return ans;
        
    }
};
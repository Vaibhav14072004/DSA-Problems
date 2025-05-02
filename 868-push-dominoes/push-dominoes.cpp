// TC= O(3*n)

class Solution {
public:
    string pushDominoes(string str) {
        int n= str.length();
        vector<int> rightForce(n,-1); // calculate it from moving from left
        vector<int> leftForce(n,-1);  // calculate it from moving to right
        
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'R'){
                rightForce[i]= i;
            }
            else if(str[i]== '.')
            {
                if(i> 0)
                {
                    rightForce[i]= rightForce[i-1];
                }
            }
        }

        for(int i=n-1; i>=0; i--)
        {
            if(str[i]== 'L'){
                leftForce[i]= i;
            }
            else if(str[i]== '.')
            {
                if(i != n-1)
                {
                    leftForce[i]= leftForce[i+1];
                }
            }
        }

        string output= "";
        for(int i=0; i<n; i++)
        {
            int leftF= abs(i-leftForce[i]);
            int rightF= abs(i-rightForce[i]);

            if(rightForce[i]== leftForce[i])
            {
                output+= '.';
            }
            else if(rightForce[i]== -1)
            {
                output+= 'L';
            }
            else if(leftForce[i]== -1)
            {
                output+= 'R';
            }
            else if(leftF== rightF)
            {
                output+= '.';
            }
            else if(leftF > rightF)
            {
                output+= 'R';
            }
            else if(leftF < rightF)
            {
                output+= 'L';
            }     
        }
     return output;   
    }
};
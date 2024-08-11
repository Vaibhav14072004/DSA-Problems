// TC= O(N*M)

/* Base case ->> when we have to only traverse the middle row atlast
    when all others paths are traversed...  
   Added 2 extra checks if(top <= bottom)  and other is if(left<= right)
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n,0));

        // Traverse the matrix in spiral form and put square in it..

        int top= 0, bottom= n-1;
        int left= 0, right= n-1;
        
        int no= 1;
        while(left <= right && top<= bottom)
        {   
            // move left...
            for(int i= left; i<= right; i++)
            {
                ans[top][i]= no++;
            }

            top++;

            // move bottom...
            for(int i=top; i<= bottom; i++)
            {
                ans[i][right]= no++; 
            }

            right--;

            // move left...

            if(top<= bottom)
            {
               for(int i=right; i>= left; i--)
               {
                  ans[bottom][i]= no++;
               }
               bottom--;
            }

            // move up...

            if(left <= right)
            {
               for(int i= bottom; i>= top; i--)
               {
                  ans[i][left]= no++;
               }
             left++;
            }
        }

       return ans; 
    }
};
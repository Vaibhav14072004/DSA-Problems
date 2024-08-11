// TC= O(N*M)
// Base case ->> when we have to only traverse the middle row atlast when all others paths are traversed...  
//    Added 2 extra checks if(top <= bottom)   and other is if(left<= right)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();

        int left= 0, right= m-1;
        int top= 0, bottom= n-1;

        vector<int> ans;
        while(left <= right && top <= bottom)
        {
            // first move right...
             for(int i= left; i<= right; i++)
             {
                ans.push_back(matrix[top][i]);
             }

             top++;
            
            // then move bottom...
             for(int i=top; i<= bottom; i++)
             {
                ans.push_back(matrix[i][right]);
             }
             
             right--;

             // then move left...

             if(top <= bottom)
             {
                for(int i=right; i>= left; i--)
                {
                ans.push_back(matrix[bottom][i]);
                }

               bottom--;
             }


             // move up...
             
             if(left <= right)
             {
                for(int i=bottom; i>= top; i--)
                {
                  ans.push_back(matrix[i][left]);
                }

              left++;
            }
        }

       return ans;

    }
};
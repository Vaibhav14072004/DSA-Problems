// Ques of Greedy Approach

/*   Intuition ->>> 
First cut that part having max cost....
Sort both horizontalCut and verticalCut vectors in descending order...

Multiply horizontal cost with vertical pieces
Multiply vertical cost with horizontal pieces    

*/

// TC= O(n log n)+ O(m log m)+ O(m+n)

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {

        // sort in descendig order..
         sort(horizontalCut.rbegin(), horizontalCut.rend());
         sort(verticalCut.rbegin(), verticalCut.rend());

         int horizontalPieces= 1;
         int verticalPieces= 1;

         int i= 0, j= 0, cost= 0;
         while(i < m-1 && j < n-1)
         {
            // if price of horizontal cut is greater ... then cut horizontal piece first
             if(horizontalCut[i] >= verticalCut[j])
             {
                 cost+= horizontalCut[i]* verticalPieces;
                 horizontalPieces++;
                 i++;
             }
            
            // if price of vertica cut is greater.. then cut vertuical piece first
             else
             {
                 cost+= verticalCut[j]* horizontalPieces;
                 verticalPieces++;
                 j++;
             }
         }

         // if one array is finished .. other is not..
         while(i< m-1)
         {
            cost+= horizontalCut[i]* verticalPieces;
            horizontalPieces++;
            i++;
         }

         while(j < n-1)
         {
            cost+= verticalCut[j]* horizontalPieces;
            verticalPieces++;
            j++;
         }

    return cost;
    }
};
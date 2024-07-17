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
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        
        // sort in descending order...
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int horizontalPieces= 1;
        int verticalPieces= 1;
        int i= 0, j= 0;
        long long price= 0;
        
        while(i < m-1 && j< n-1)
        {
            if(horizontalCut[i] >= verticalCut[j])
            {
                price+= horizontalCut[i]* verticalPieces;
                horizontalPieces++;
                i++;
            }

            else
            {
                price+= verticalCut[j]* horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        while(i< m-1)
        {
            price+= horizontalCut[i]* verticalPieces;
            horizontalPieces++;
            i++;
        }

        while(j< n-1)
        {
            price+= verticalCut[j]* horizontalPieces;
            verticalPieces++;
            j++;
        }
    return price;
    }
};
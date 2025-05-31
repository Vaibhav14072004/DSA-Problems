// Approach -> Using BFS
// TC= O(N^2)

class Solution {
public:
    pair<int,int> findCoordinates(int val,int n)
    {
        int rowTop= (val-1)/n;
        int rowBottom= (n-1)-rowTop;

        int col= (val-1)% n;
        
        // zig -zag manner, we have to move to from right to left if both (n and rowBottom) is ODD or both EVEN
        if((n % 2 == 0 && rowBottom % 2== 0) || (n % 2 == 1 && rowBottom % 2 == 1))
        {
            col= (n-1)-col;
        }
        return {rowBottom,col};
    }

    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n= board.size();
        vector<vector<bool>> visited(n,vector<bool> (n,false));

        queue<int> q;
        q.push(1);
        visited[n-1][0]= true;

        int steps= 0;
        while(!q.empty())
        {
            int size= q.size();
            while(size--)
            {
                int curr= q.front();
                q.pop();

                if(curr== n*n)
                {
                    return steps;
                }

                for(int k=1; k<=6; k++)
                {
                    int val= curr+k;
                    if(val > n*n){
                        break;
                    }

                    pair<int,int> coord= findCoordinates(val,n);
                    int row= coord.first;
                    int col= coord.second;

                    if(visited[row][col]){
                        continue;
                    }

                    visited[row][col]= true;
                    if(board[row][col]== -1)
                    {
                        q.push(val);
                    }
                    else
                    {
                        q.push(board[row][col]);
                    }
                }
            }
          steps++;
        }

    return -1;
    }
};
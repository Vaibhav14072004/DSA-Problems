// Approach -> Using Backtracking
// TC= O(N*M* (4^n))

class Solution {
public:
    vector<int> dirX= {-1,0,1,0};
    vector<int> dirY= {0,1,0,-1};

   bool find(int i, int j,vector<vector<char>> &board,int idx,string &word,int n, int m)
   {
        if(idx>= word.length()){
            return true;
        }

        if(i < 0 || j< 0 || i>= n || j>= m){
            return false;
        }
        
        // if it is already visited, return false..
        if(board[i][j]== '*' || board[i][j] != word[idx]){
            return false;
        }

        // mark board[i][j] as visited...
        char temp= board[i][j];
        board[i][j]= '*';

        for(int k=0; k<4; k++)
        {
            int ni= i+ dirX[k];
            int nj= j+ dirY[k];
            if(find(ni,nj,board,idx+1,word,n,m))
            {
                return true;
            }
        }

        // backtracking...
        board[i][j]= temp;

   return false;
   }


    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m= board[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]== word[0] && find(i,j,board,0,word,n,m)){
                    return true;
                }
            }
        }
    return false;
    }
};




// Approach 2 => Making only 1 function search...
// Part 2) Recursively calling search(x+1,0, ) search(x,y+1) .....

/*

class Solution{
public:
     bool search(int i, int j, int index, int n, int m, string &word, vector<vector<int>> &visited, vector<vector<char>> &board)
     {
         if(i<0 || i>=n || j<0 || j>=m || visited[i][j]== 1 || word[index] != board[i][j])
         {
             return false;
         }

         // base case
         if(index== word.size()-1){
             return true;
         }

         visited[i][j]= 1;

         bool found= false;
         found= search(i-1, j,index+1,n,m,word,visited,board) || search(i, j+1,index+1,n,m,word,visited,board) ||
                search(i+1, j,index+1,n,m,word,visited,board) || search(i, j-1,index+1,n,m,word,visited,board);
        
        // backtracking...
        visited[i][j]= 0; 
        return found;
     }
     
     
      bool exist(vector<vector<char>>& board, string word) {
         int n= board.size();
         int m= board[0].size();  
         vector<vector<int>> visited(n, vector<int> (m,0));
         
         for(int i=0; i<n; i++)
         {
             for(int j=0; j<m; j++)
             {
                 if(search(i, j, 0, n, m, word, visited, board)){
                     return true;
                 }
             }
         }
         return false;
      }
};

*/




// ----TLE----
// Approach 2 =>> Making only 1 function search...
// Part 1) Running for loop for dx, dy  =>> Giving TLE..

/*

class Solution {
public:
    bool search(int i, int j, int index,int n, int m, string word, vector<vector<int>> &visited, vector<vector<char>> &board)
    {
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j]== 1 || word[index] != board[i][j])
        {
            return false;
        }

        if(index== word.size()-1){
            return true;
        }

        visited[i][j]= 1;

        vector<int> dx= {-1,0,1,0};
        vector<int> dy= {0,1,0,-1};

        for(int l= 0; l<4; l++)
        {
             int nx= i+ dx[l];
             int ny= j+ dy[l];
            if(search(nx,ny, index+1, n,m, word,visited,board)){
                return true;
            }
        }

        visited[i][j]= 0; // backTracking...
        return false;
    }



    bool exist(vector<vector<char>>& board, string word) {
         int n= board.size();
         int m= board[0].size();
         int size= word.size();

         vector<vector<int>> visited(n, vector<int>(m,0));

         for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(search(i,j,0,n,m,word,visited,board))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
*/


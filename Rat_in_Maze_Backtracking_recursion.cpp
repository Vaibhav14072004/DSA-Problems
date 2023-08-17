#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
    {

        if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && arr[newx][newy] == 1)
        {

            return true;
        }
        else
        {
            return false;
        }
    }

    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
    {

        // base case ==>> Reached the destination..
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        /*  4 Movements ==> Down(D)  Left(L)  Right(R)  Up(U)
            According to lexographical order =>> ie Alphabetically    */

        // mark visited as true on reaching a particular position
        visited[x][y] = 1;

        // 1. Down =>  x+1 , y
        if (isSafe(x + 1, y, visited, arr, n))
        {
            solve(x + 1, y, arr, n, ans, visited, path + "D");
        }

        // 2. Left => x, y-1
        if (isSafe(x, y - 1, visited, arr, n))
        {
            solve(x, y - 1, arr, n, ans, visited, path + "L");
        }

        // 3. Right => x, y+1
        if (isSafe(x, y + 1, visited, arr, n))
        {
            solve(x, y + 1, arr, n, ans, visited, path + "R");
        }

        // 4. Up => x-1, y
        if (isSafe(x - 1, y, visited, arr, n))
        {
            solve(x - 1, y, arr, n, ans, visited, path + "U");
        }

        // Backtracking.......
        visited[x][y] = 0;
    }

    vector<string> searchMaze(vector<vector<int>> &arr, int n)
    {
        vector<string> ans;
        string path = "";

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        /*  vector <bool> (n,false) ==>> means vector of type bool where n
         elements initialised with false   */

        // base case ==>> if we have NOT at the initial position (0,0) then directly return ans
        if (arr[0][0] == 0)
        {
            return ans;
        }

        solve(0, 0, arr, n, ans, visited, path);
        return ans;
    }
};

int main()
{
    Solution s;

    /* If we have to do only on standard 4*4 matrix values..
    int n=4;
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    */

    // If we have to take input....
    int n;
    cout << "No of rows or columns of maze: " << endl;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    cout << "Enter the maze matrix (0 or 1):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<string> output = s.searchMaze(arr, n);
    if (output.empty())
    {
        cout << "No paths found to reach the destination.\n";
    }
    else
    {
        cout << "Possible paths to reach the destination:\n";

        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << "\n";
        }
    }

    return 0;
}

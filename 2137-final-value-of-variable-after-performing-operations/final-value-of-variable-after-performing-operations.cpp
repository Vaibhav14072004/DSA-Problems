class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n= operations.size();
        int cnt= 0;
        for(string it: operations)
        {
            if(it== "--X" || it== "X--") cnt--;
            else cnt++;
        }
      return cnt;  
    }
};
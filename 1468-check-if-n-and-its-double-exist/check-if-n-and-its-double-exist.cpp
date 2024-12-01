// TC= O(2*N)

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n= arr.size();

        unordered_set<int> st;
        int zeroCnt= 0;

        for(int i=0; i<n; i++)
        {
           if(arr[i]== 0) zeroCnt++;
           st.insert(arr[i]);
        }
        
        // there should be 2 or more pairs of 0
        if(zeroCnt > 1) return true;

        for(int i=0; i<n; i++)
        {
            if(arr[i] != 0 && st.find(2* arr[i]) != st.end())
            {
               return true;
            }
        }
        return false;
    }
};
// Approach 2 
// Tc= O(N)

class Solution 
{
public:

    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
            for(int j=i-1;j>=0;j--)
            {
                if((arr[i]|arr[j])==arr[j])
                {
                    break;
                }
                arr[j]|=arr[i];
                st.insert(arr[j]);
            }
        }
        return st.size();
    }
};





// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n= arr.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++)
        {
            int OR= 0;
            for(int j=i; j<n; j++)
            {
                OR |= arr[j];
                st.insert(OR);
            }
        }
      return st.size();  
    }
};

*/
// Approach 2 -> Sliding Window Approach
// TC= O(N)

class Solution{
 public: 
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
        int n= arr.size();
        int ans= 0;

        // first append k-1 elements at the end of arr to maintain circular property..
        arr.insert(arr.end(), arr.begin(), arr.begin()+k-1);

        int i=0, j= 1;
        int N= n+k-1;
        while(j < N)
        {
            if(arr[j-1] == arr[j])
            {
                i= j;
                j++;
                continue;
            }

            if(j-i+1== k)
            {
                ans++;
                i++;
            }
          j++;  
        }
    return ans;
    }
};






//   -----   TLE -------
// Approach 1 -> Brute Force Approach
// TC= O(N*K)

/*

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
        int n= arr.size();
        int ans= 0;
        
        // base case
        if(n < k) return 0;

        // first append k-1 elements of arr in end of arr again
        arr.insert(arr.end(), arr.begin(), arr.begin()+k-1);

        for(int i=0; i<n; i++)
        {
            int cnt= 0;
            for(int j=i+1; j< i+k; j++)
            {
                if(arr[j-1] != arr[j])
                {
                    cnt++;
                }
            }
            
            // k-1 pairs, have k length
            if(cnt== k-1)
            {
                ans++;
            }
        }
 
      return ans;  
    }
};

*/